#define _CRT_SECURE_NO_WARNINGS
#include "Discord.hpp"
#include <Windows.h>
#include <array>
#include <fstream>

/*
    Discord class
    @file Discord.cpp
    @author miaouCorp
    @version 1.2
*/

bool Discord::checkDiscord()
{
    std::string const PATH{ "\\AppData\\Local\\Discord\\" };
    std::string const LOOKME{ getenv("USERPROFILE") + PATH + "Update.exe" };
    std::ifstream file{ LOOKME.c_str(), std::ifstream::in | std::ifstream::binary };

    if (!file.is_open())
        return false;

    return this->DiscordInstalled = true;
}

bool Discord::killDiscord()
{
    for (int i = 0; i < 10; i++)
    {
        DWORD pID;
        HWND window{ FindWindowEx(0, 0, "Chrome_WidgetWin_1", 0) };
        GetWindowThreadProcessId(window, &pID);
        HANDLE pHandle{ OpenProcess(PROCESS_TERMINATE, FALSE, pID) };
        TerminateProcess(pHandle, 1);
        CloseHandle(pHandle);
    }
    return this->DiscordKilled = true;
}

bool Discord::restartDiscord()
{
    std::string const PROFILE{ getenv("USERPROFILE") };
    std::string const PATH{ "\\AppData\\Local\\Discord\\" };
    std::string const LOOKME{ PROFILE + PATH + "Update.exe --processStart Discord.exe"};
    if (!system(LOOKME.c_str()))
        return this->DiscordRestarted = true;
    return false;
}

// A FINIR QUAND INJECTION JS FINI

bool Discord::injectDiscord()
{
    std::string resultPath{ "" };
    std::string const PATH{ "\\AppData\\Local\\Discord\\app-1.0.9005\\modules\\" };
    std::array<std::string, 3> discordDesktopCore{"discord_desktop_core-3","discord_desktop_core-2", "discord_desktop_core-1"};
    
    for(int n{ 0 }; n <= 2; n++)
    {
        std::string const LOOKME{ getenv("USERPROFILE") + PATH + discordDesktopCore[n] + "\\discord_desktop_core\\index.js" };
        std::ifstream file{ LOOKME.c_str(), std::ifstream::in | std::ifstream::binary };

        if (!file.is_open())
        {
            NULL;
        } else {
            resultPath = LOOKME;
            break;
        }
    }
    std::cout << "\nhey: " << resultPath << "\n";
    return this->InjectionWrited = true;
}

bool Discord::isInjectionWrited() const
{
    return this->InjectionWrited;
}

bool Discord::isDiscordInstalled() const
{
    return this->DiscordInstalled;
}

bool Discord::isDiscordKilled() const
{
    return this->DiscordKilled;
}

bool Discord::isDiscordRestarted() const
{
    return this->DiscordRestarted;
}