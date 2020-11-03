#include <iostream>
#include <fstream>
#include "save.h"
#include "open_dna_file_error.h"


std::string Save::execute(const std::vector<std::string>& input, IDNADataCollection* DNADataCol)const
{
	size_t inputLength = input.size();
	if(inputLength < 2 || inputLength > 3)
	{
		throw InvalidCommand();
	}
	DNAData DNAD = DNADataCol->getDNAData(input[1]);
	std::cout<<DNADataCol->getDNAData(input[1]).getDNASeq();
	/*try
	{
		
		if(2 == inputLength)
		{
			newDNA.writeToFile(input[2].c_str());
		}	
		else // inputLength=3
		{
			newDNA.writeToFile(input[2].c_str());
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
	}*/
	return "\0";
	
}

