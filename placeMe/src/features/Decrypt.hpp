#pragma once
#ifndef DECRYPT_HPP
#define DECRYPT_HPP

#include "Core.hpp"

/*
    Decrypt Xor class-based & Base64 implementation
    @file Decrypt.hpp
    @author miaouCorp
    @version 1.1
*/

class Cipher : public Core
{
    public:
        std::string decrypt(std::string& key, std::string& data);
        std::string encrypt(std::string& key, std::string& data);
        std::string base64Decode(const std::string& data);
        std::string base64Encode(const std::string& data);

        // I know ><
        std::string superDecrypt(std::string key, std::string data)
        {
            std::string decoded{ base64Decode(data) };
            return decrypt(key, decoded);
        }

        std::string superEncrypt( std::string key, std::string data)
        {
            std::string encoded{ encrypt(key, data) };
            return base64Encode(encoded);
        }
};

#endif