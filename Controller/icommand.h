#ifndef __ICOMMAND_H__
#define __ICOMMAND_H__

#include <iostream>
#include <vector>
#include "Model/iDNA_data_collection.h"
#include "invalid_command.h"

class ICommand
{
public:
	virtual ~ICommand(){};
	virtual std::string execute(const std::vector<std::string>& input, IDNADataCollection* DNADataCol) const = 0; 
	//TODO add function thats check if input length is valid and a function thats make a returnValueStr
};

#endif //__ICOMMAND_H__
