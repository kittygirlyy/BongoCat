#include "Core.hpp"

/*
	Our super-Class
	@file Core.cpp
	@author miaouCorp
	@version 1.0
*/

void Core::setKey(const int& k)
{
	this->key = k;
}

void Core::setEndPoint(const std::string& eP)
{
	this->endPoint = eP;
}

std::string Core::getEndPoint()
{
	return this->endPoint;
}

int Core::getKey()
{
	return this->key;
}