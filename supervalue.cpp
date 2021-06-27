#include "supervalue.h"

Super::Super()
	: type('n'), integerValue(0), doubleValue(0.0), boolValue(0), charValue(0), stringValue(""), typeLock(0)
{}

Super::Super(int v, bool t)
	: type('i'), integerValue(v), doubleValue(0.0), boolValue(0), charValue(0), stringValue(""), typeLock(0)
{}

Super::Super(double v, bool t)
	: type('d'), integerValue(0), doubleValue(v), boolValue(0), charValue(0), stringValue(""), typeLock(0)
{}

Super::Super(bool v, bool t)
	: type('b'), integerValue(0), doubleValue(0.0), boolValue(v), charValue(0), stringValue(""), typeLock(0)
{}

Super::Super(char v, bool t)
	: type('c'), integerValue(0), doubleValue(0.0), boolValue(0), charValue(v), stringValue(""), typeLock(0)
{}

Super::Super(std::string v, bool t)
	: type('s'), integerValue(0), doubleValue(0.0), boolValue(0), charValue(0), stringValue(v), typeLock(0)
{}
