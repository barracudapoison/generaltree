#include "super.h"
#include <cstring>
#include <vector>
#include <iostream>
#include <string>


void Super::setValueRaw(char c, std::vector<unsigned char> v)
{
	type = c;
	value = v;
}

template<typename T>
void Super::setValue(char c, T val)
{
	value.clear();
	for (int i = 0; i < sizeof(T); ++i)
	{
		value.push_back(*((unsigned char *)&val + i));
	}
	std::cout << sizeof(value) << std::endl;
}

void Super::setStringValue( char c, const std::string str )
{
	value.clear();
	for (int i = 0; i < str.size(); i++)
	{
		value.push_back((unsigned char)str[i]);
	}
}

Super::Super()
	: type('n'), value({})
{
}


template void Super::setValue<bool>				(char, bool				);
template void Super::setValue<unsigned int>		(char, unsigned int		);
template void Super::setValue<signed int>		(char, signed int		);
template void Super::setValue<float>			(char, float			);
template void Super::setValue<double>			(char, double			);
template void Super::setValue<unsigned char>	(char, unsigned char	);
template void Super::setValue<signed char>		(char, signed char		);
