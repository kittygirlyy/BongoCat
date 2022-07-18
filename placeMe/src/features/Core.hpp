#pragma once
#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>

#include "../lib/httpReq/HTTPRequest.hpp"

/*
	Our super-Class
	@file Core.hpp
	@author miaouCorp
	@version 1.1
*/

class Core
{
	protected:
		std::string endPoint;
		std::string key;
		std::string uKey;

	public:

		std::string getEndPoint();
		std::string getKey();
		std::string parseBase(const std::string& KEP);

		void setEndPoint(const std::string& eP);
		void setKey(const std::string& k);
		
};

#endif