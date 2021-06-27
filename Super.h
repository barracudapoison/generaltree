#ifndef SUPER_H
#define SUPER
#pragma once

#include <vector>
#include <string>

struct Super
{
	char type;
	std::vector<unsigned char> value;

	void setValueRaw(char, std::vector<unsigned char>);
	
	template <typename T>
	void setValue(char, T);
	void setStringValue(char, const std::string);

	Super();

};

#endif
