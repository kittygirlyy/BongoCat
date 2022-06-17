#include "Decrypt.hpp"

/*
    Decrypt Xor class-based
    @file Decrypt.cpp
    @author miaouCorp
    @version 1.0
*/

std::string Xor::decrypt(const int& key, std::string& data)
{
    std::string dData{ "" };
    for(auto& c : data) { 
        char dChar{ char(c ^ key) };
        dData += dChar;
    }
    return dData;
}

std::string Xor::encrypt(const int& key, std::string& data)
{
    std::string eData{ "" };
    for(auto& c : data) {
        char eChar{ char(c ^ key) };
        eData += eChar;
    }
    return eData;
}