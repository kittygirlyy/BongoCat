#define _CRT_SECURE_NO_WARNINGS
#include "Discord.hpp"
#include <fstream>

/*
    Discord class
    @file Discord.cpp
    @author miaouCorp
    @version 1.0
*/

bool Discord::checkDiscord()
{
    std::string const PATH{ "\\AppData\\Local\\Discord\\" };
    std::string const LOOKME{ getenv("USERPROFILE") + PATH + "Update.exe" };
    std::ifstream file{ LOOKME.c_str(), std::ifstream::in | std::ifstream::binary };

    if (!file.is_open())
        return false;

    this->isDone = true;
    return true;
}

bool Discord::isDiscordDone()
{
    return this->isDone;
}