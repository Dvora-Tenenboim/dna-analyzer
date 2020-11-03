#include <iostream>
#include <vector>
#include "CLI.h"
#include "icommand.h"
#include "invalid_command.h"

std::vector<std::string> splitToWords(const std::string& str)
{
	std::vector<std::string> vecOfWords;
	std::string word;
	size_t strLength = str.length();
	for(size_t i=0; i < strLength; i++)
	{
		word = "";
		while(str[i] != ' ' && i < strLength)
		{
			word += str[i++];
		}
		vecOfWords.push_back(word);
	}
	return vecOfWords;
}

void CLI::executeCommands(CommandCollection* cmdCollection, DNADataCollection* DNADataCol, IReader* reader, IWriter* writer)const
{
	std::string userInput;
	std::string commandOutPut;
	std::vector<std::string> splitInput;
	const ICommand* command;
	while(true)
	{
		writer->write("> cmd >>> ");
		userInput = reader->read();
		if (userInput == "quit")
		{
			writer->write("> cmd >>> Good bye\n");
			return;
		}
		splitInput = splitToWords(userInput);
		try
		{
			command = cmdCollection -> getCommand(splitInput[0]);
			commandOutPut = command->execute(splitInput, DNADataCol);
			writer->write(commandOutPut + "\n");
		}
		catch(InvalidCommand& e)
		{
			commandOutPut = "> cmd >>> ";
			commandOutPut  += e.what();
			commandOutPut += "\n";
			writer->write(commandOutPut);
		}
		catch(InvalidNucleotide& e)
		{
			commandOutPut = "> cmd >>> ";
			commandOutPut  += e.what();
			commandOutPut += "\n";
			writer->write(commandOutPut);
		}
		
	}
}

