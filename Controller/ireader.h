#ifndef __IREADER_H__
#define __IREADER_H__

#include <iostream>

class IReader
{
public:
	virtual std::string read() const = 0;
};

#endif // __IREADER_H__
