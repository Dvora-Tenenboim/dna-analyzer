#ifndef __CLI_H__
#define __CLI_H__

#include "command_collection.h"
#include "DNA_data_collection.h"
#include "ireader.h"
#include "iwriter.h"

//TODO creat interphase for command_collection and DNA_data_collection
class CLI
{
public:
	void executeCommands(CommandCollection* cmdCollection, DNADataCollection* DNADataCol, IReader* reader, IWriter* writer)const;
};

#endif


