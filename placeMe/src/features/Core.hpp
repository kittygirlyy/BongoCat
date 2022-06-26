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
	private:
		std::string endPoint;
		std::string key;

	public:
		std::string getEndPoint();
		std::string getKey();
		void setEndPoint(const std::string& eP);
		void setKey(const std::string& k);
};

#endif