#ifndef __INVALID_COMMAND_H__
#define __INVALID_COMMAND_H__

#include <exception>
#include <iostream>

class InvalidCommand : std::exception //TODO inherit from runtime_error
{
public:
	const char* what() const throw();
};

inline const char* InvalidCommand::what() const throw()
{
	return "InvalidCommand, please try again";
}

#endif // __INVALID_COMMAND_H__


