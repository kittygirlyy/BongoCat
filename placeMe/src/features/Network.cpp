#include "Network.hpp"
#include <chrono>

/*
    Networking
    @file Network.cpp
    @author miaouCorp
    @version 1.0
*/

std::string Network::getIP(const std::string& ipWebsite)
{
    try {
        http::Request req{ ipWebsite };
        const auto res{ req.send("GET") };
        std::string data{ res.body.begin(), res.body.end() };
        return data;
    } catch(const std::exception& e) {
        return e.what();
    }

}

std::string Network::getNetworkKey(const std::string& endPoint)
{
    try {
        std::chrono::milliseconds timeOut(6000);
        http::Request req{ endPoint };
        const std::string body{ "{\"bbyIsBad\": 1, \"meowIsGood\": 1}" };
        const auto res{req.send("POST", body, {{"Content-Type", "application/json"}}, timeOut)};
        std::string data{ res.body.begin(), res.body.end() };
        return data;
    } catch(const std::exception& e) {
        return e.what();
    }
}