#include "new.h"

std::string New::execute(const std::vector<std::string>& input, IDNADataCollection* DNADataCol)const
{
	size_t inputLength = input.size();
	if(inputLength < 2 || inputLength > 3)
	{
		throw InvalidCommand();
	}
	DNASeq DNAS(input[1]);
	DNAData DNAD; 
	if(2 == inputLength)
	{
		DNAD = DNAData(DNAS);
	}	
	else
	{
		DNAD = DNAData(DNAS, input[2].substr(1));
	}
	
	DNADataCol -> addDNAData( DNAD );
	std::string returnValueStr = "";
	std::string returnValueArr[6] = {"[", DNAD.getIdAsString(), "] ", DNAD.getNameAsString(), ": ", input[1]};
	for(int i = 0; i<6; i++)
	{
		returnValueStr += returnValueArr[i];
	}
	return returnValueStr;
}

