#pragma once
#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include "../lib/httpReq/HTTPRequest.hpp"

/*
	Our super-Class
	@file Core.hpp
	@author miaouCorp
	@version 1.0
*/

class Core
{
	private:
		std::string endPoint;
		int key;

	public:
		std::string getEndPoint();
		int getKey();
		void setEndPoint(const std::string& eP);
		void setKey(const int& k);
};

#endif