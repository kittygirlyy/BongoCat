#pragma once
#include <iostream>

/*
    Decrypt Xor class-based & Base64 implementation
    @file Decrypt.hpp
    @author miaouCorp
    @version 1.1
*/

class Cipher
{
    public:
        std::string decrypt(const int& key, std::string& data);
        std::string encrypt(const int& key, std::string& data);
        std::string base64Decode(const std::string& data);
        std::string base64Encode(const std::string& data);

        // I know ><
        std::string superDecrypt(const int& key, const std::string& data)
        {
            std::string decoded{ base64Decode(data) };
            return decrypt(key, decoded);
        }
};