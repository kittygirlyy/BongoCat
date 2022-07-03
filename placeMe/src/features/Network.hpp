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
        std::string getIP(const std::string& ipWebsite);
        std::string getNetworkKey(const std::string& endPoint);
};

#endif