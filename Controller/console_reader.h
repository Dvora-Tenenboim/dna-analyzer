#ifndef __CONSOLE_READER_H__
#define __CONSOLE_READER_H__

#include <iostream>
#include "ireader.h"

class ConsoleReader:public IReader
{
	std::string read() const;
};

inline std::string ConsoleReader::read()const
{
	std::string input;
	getline(std::cin, input);
	return input;
}

#endif // __CONSOLE_READER_H__
