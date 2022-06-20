#pragma once
#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "Core.hpp"

/*
    Networking
    @file Network.hpp
    @author miaouCorp
    @version 1.0
*/

class Network : public Core
{
    public:
        const char* getIP(const std::string& ipWebsite);
        const char* getNetworkKey(const std::string& endPoint);
};

#endif