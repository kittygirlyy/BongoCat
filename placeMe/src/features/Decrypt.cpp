#include "Decrypt.hpp"

/*
    Decrypt Xor class-based & Base64 implementation
    @file Decrypt.cpp
    @author miaouCorp
    @version 1.1
*/

static constexpr const std::byte ENCODING_TABLE[]{
    std::byte{'A'}, std::byte{'B'}, std::byte{'C'}, std::byte{'D'},
    std::byte{'E'}, std::byte{'F'}, std::byte{'G'}, std::byte{'H'},
    std::byte{'I'}, std::byte{'J'}, std::byte{'K'}, std::byte{'L'},
    std::byte{'M'}, std::byte{'N'}, std::byte{'O'}, std::byte{'P'},
    std::byte{'Q'}, std::byte{'R'}, std::byte{'S'}, std::byte{'T'},
    std::byte{'U'}, std::byte{'V'}, std::byte{'W'}, std::byte{'X'},
    std::byte{'Y'}, std::byte{'Z'}, std::byte{'a'}, std::byte{'b'},
    std::byte{'c'}, std::byte{'d'}, std::byte{'e'}, std::byte{'f'},
    std::byte{'g'}, std::byte{'h'}, std::byte{'i'}, std::byte{'j'},
    std::byte{'k'}, std::byte{'l'}, std::byte{'m'}, std::byte{'n'},
    std::byte{'o'}, std::byte{'p'}, std::byte{'q'}, std::byte{'r'},
    std::byte{'s'}, std::byte{'t'}, std::byte{'u'}, std::byte{'v'},
    std::byte{'w'}, std::byte{'x'}, std::byte{'y'}, std::byte{'z'},
    std::byte{'0'}, std::byte{'1'}, std::byte{'2'}, std::byte{'3'},
    std::byte{'4'}, std::byte{'5'}, std::byte{'6'}, std::byte{'7'},
    std::byte{'8'}, std::byte{'9'}, std::byte{'+'}, std::byte{'/'},
};

template <std::size_t n>
inline constexpr void encode(const std::byte src[n], std::byte dst[4]) noexcept;

template <>
inline constexpr void encode<3>(const std::byte src[3],
    std::byte       dst[4]) noexcept {
    auto I0 = src[0] >> 2;
    auto I1 = src[0] << 6 >> 2 | src[1] >> 4;
    auto I2 = src[1] << 4 >> 2 | src[2] >> 6;
    auto I3 = src[2] << 2 >> 2;

    dst[0] = ENCODING_TABLE[static_cast<int>(I0)];
    dst[1] = ENCODING_TABLE[static_cast<int>(I1)];
    dst[2] = ENCODING_TABLE[static_cast<int>(I2)];
    dst[3] = ENCODING_TABLE[static_cast<int>(I3)];
}

template <>
inline constexpr void encode<2>(const std::byte src[2],
    std::byte       dst[4]) noexcept {
    auto I0 = src[0] >> 2;
    auto I1 = src[0] << 6 >> 2 | src[1] >> 4;
    auto I2 = src[1] << 4 >> 2;

    dst[0] = ENCODING_TABLE[static_cast<int>(I0)];
    dst[1] = ENCODING_TABLE[static_cast<int>(I1)];
    dst[2] = ENCODING_TABLE[static_cast<int>(I2)];
    dst[3] = std::byte{ '=' };
}

template <>
inline constexpr void encode<1>(const std::byte src[1],
    std::byte       dst[4]) noexcept {
    auto I0 = src[0] >> 2;
    auto I1 = src[0] << 6 >> 2;

    dst[0] = ENCODING_TABLE[static_cast<int>(I0)];
    dst[1] = ENCODING_TABLE[static_cast<int>(I1)];
    dst[2] = std::byte{ '=' };
    dst[3] = std::byte{ '=' };
}

inline constexpr std::byte find(std::byte b) noexcept {
    for(auto offset = 0u; offset < 64u; ++offset) {
        if (ENCODING_TABLE[offset] == b) {
            return std::byte(offset);
        }
    }
    return std::byte(0);
}

template <std::size_t n>
inline constexpr void decode(const std::byte src[4], std::byte dst[3]) noexcept;

template <>
inline constexpr void decode<4>(const std::byte src[4],
    std::byte       dst[3]) noexcept {
    auto O0 = find(src[0]);
    auto O1 = find(src[1]);
    auto O2 = find(src[2]);
    auto O3 = find(src[3]);

    dst[0] = O0 << 2 | O1 >> 4;
    dst[1] = O1 << 4 | O2 >> 2;
    dst[2] = O2 << 6 | O3;
}


std::string Cipher::decrypt(std::string& key, std::string& data)
{
    std::string tmp{ key };
    while(key.size() < data.size())
        key += tmp;

    for(std::string::size_type i = 0; i < data.size(); ++i)
        data[i] ^= key[i];
    return data;
}

std::string Cipher::encrypt(std::string& key, std::string& data)
{
    std::string tmp{ key };
    while(key.size() < data.size())
        key += tmp;

    for(std::string::size_type i = 0; i < data.size(); ++i)
        data[i] ^= key[i];
    return data;
}

std::string Cipher::base64Decode(const std::string& data)
{
    const auto len = data.size();
    const auto nh = len / 4;

    std::string decoded;
    decoded.resize(3 * nh);

    auto src = reinterpret_cast<const std::byte*>(data.data());
    auto dst = reinterpret_cast<std::byte*>(decoded.data());
    for(auto chunk = 0u; chunk < nh; ++chunk, src += 4, dst += 3) {
        decode<4>(src, dst);
    }

    while(decoded.back() == '\0') {
        decoded.pop_back();
    }

    return decoded;
}

std::string Cipher::base64Encode(const std::string& data)
{
    const auto len = data.size();
    const auto nh = len / 3;
    const auto nt = len - 3 * nh;
    const auto nx = nt ? 4 : 0;

    std::string encoded;
    encoded.resize(4 * nh + nx);

    auto src = reinterpret_cast<const std::byte*>(data.data());
    auto dst = reinterpret_cast<std::byte*>(encoded.data());
    for(auto chunk = 0u; chunk < nh; ++chunk, src += 3, dst += 4) {
        encode<3>(src, dst);
    }

    switch (nt) {
    case 2:
        encode<2>(src, dst);
        break;
    case 1:
        encode<1>(src, dst);
        break;
    default:
        break;
    }

    return encoded;
}