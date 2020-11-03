#ifndef __IWRITER_H__
#define __IWRITER_H__

#include <iostream>

class IWriter
{
public:
	virtual void write(const std::string& str)const = 0;
};

#endif // __IWRITER_H__
