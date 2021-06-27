#ifndef SUPERVALUE_H
#define SUPERVALUE_H
#pragma once

#include <string>

class Super
{
	private:
		char type;

		int integerValue;
		double doubleValue;
		bool boolValue;
		char charValue;
		std::string stringValue;

		bool typeLock; // means the type cannot be changed

			

	public:
		std::string getValue();

		Super();
		Super(int, bool);
		Super(double, bool);
		Super(bool, bool);
		Super(char, bool);
		Super(std::string, bool);
};

#endif
