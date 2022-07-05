#include "Core.hpp"

/*
	Our super-Class
	@file Core.cpp
	@author miaouCorp
	@version 1.0
*/

void Core::setKey(const std::string& k)
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

std::string Core::getKey()
{
	return this->key;
}

std::vector<std::string> splitBase(const std::string& string, char delim)
{
	std::vector<std::string> result;
	std::stringstream stringAk(string);
	std::string item;

	while(getline(stringAk, item, delim))
	{
		result.push_back(item);
	}
	return result;
}


std::string Core::parseBase(const std::string& KEP)
{
	std::vector<std::string> result{ splitBase(KEP, ':')};

	return this->endPoint = result[0].erase(0, 1), this->key = result[1].erase(result[1].size() - 2);
}