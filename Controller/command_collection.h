#ifndef __COMMAND_COLLECTION_H__
#define __COMMAND_COLLECTION_H__

#include <map>
#include "icommand.h"

class CommandCollection
{
public:
	CommandCollection();
	~CommandCollection();
	const ICommand* getCommand(const std::string& str);

private:
	std::map<std::string, ICommand*> m_commands;
};

#endif // __COMMAND_COLLECTION_H__
