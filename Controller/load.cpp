#include <iostream>
#include <fstream>
#include "load.h"
#include "open_dna_file_error.h"


std::string Load::execute(const std::vector<std::string>& input, IDNADataCollection* DNADataCol)const
{
	size_t inputLength = input.size();
	if(inputLength < 2 || inputLength > 3)
	{
		throw InvalidCommand();
	}
	DNASeq newDNA;
	DNAData DNAD;
	try
	{
		newDNA.readFromFile(input[1].c_str());
		if(2 == inputLength)
		{
			DNAD = DNAData(newDNA, input[1]);
		}	
		else
		{
			DNAD = DNAData(newDNA, input[2].substr(1));
		}
		DNADataCol -> addDNAData( DNAD );
		std::string returnValueStr = "";
		std::string returnValueArr[6] = {"[", DNAD.getIdAsString(), "] ", DNAD.getNameAsString(), ": ", newDNA.getAsString()};
		for(int i = 0; i<6; i++)
		{
			returnValueStr += returnValueArr[i];
		}
		return returnValueStr;
		
	}
	catch (OpenDnaFileError& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return "\0";
	
}

