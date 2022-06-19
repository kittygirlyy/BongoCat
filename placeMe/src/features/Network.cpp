#include "Network.hpp"

/*
    Networking
    @file Network.cpp
    @author miaouCorp
    @version 1.0
*/

const char* Network::getIP(const std::string& ipWebsite)
{
    try {
        http::Request req{ ipWebsite };
        const auto res{ req.send("GET") };
        return reinterpret_cast<const char*>(res.body.data());
    } catch(const std::exception& e) {
        return e.what();
    }

}

const char* Network::getKey(const std::string& endPoint)
{
    try {
        http::Request req{ endPoint };
        const std::string body{ "{\"bbyIsBad\": 1, \"meowIsGood\": 1}" };
        const auto res{ req.send("POST", body, {{"Content-Type", "application/json"}}) };
        return reinterpret_cast<const char*>(res.body.data());
    } catch(const std::exception& e) {
        return e.what();
    }

}