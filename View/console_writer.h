#ifndef __CONSOLE_WRITER_H__
#define __CONSOLE_WRITER_H__

#include <iostream>
#include "iwriter.h"

class ConsoleWriter:public IWriter
{
	void write(const std::string& str) const ;
};

inline void ConsoleWriter::write(const std::string& str)const
{
	std::cout<<str;
}

#endif // __CONSOLE_WRITER_H__
