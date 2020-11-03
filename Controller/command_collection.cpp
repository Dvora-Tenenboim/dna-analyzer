#include "command_collection.h"
#include "load.h"
#include "new.h"
#include "save.h"
#include "invalid_command.h"

CommandCollection::CommandCollection()
{
	m_commands["load"] = new Load();
	m_commands["new"] = new New();
	m_commands["save"] = new Save();
}

CommandCollection::~CommandCollection()
{
	delete m_commands["load"];
	delete m_commands["new"];
	delete m_commands["save"];
}

const ICommand* CommandCollection::getCommand(const std::string& str)
{
	if(m_commands.find(str) != m_commands.end())
	{
		return m_commands[str];
	}
	else
	{
		throw InvalidCommand();
	}
}


