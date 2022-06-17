#pragma once
#include <iostream>
#include <vector>

/*
    Decrypt Xor class-based
    @file Decrypt.hpp
    @author miaouCorp
    @version 1.0
*/

class Xor
{
    public:
        std::string decrypt(const int& key, std::string& data);
        std::string encrypt(const int& key, std::string& data);
};