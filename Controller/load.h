#ifndef __LOAD_H__
#define __LOAD_H__ 

#include <iostream>
#include <vector>
#include "icommand.h"

class Load:public ICommand
{
public:
	/*virtual*/ std::string execute(const std::vector<std::string>& input, IDNADataCollection* DNADataCol) const;
};

#endif // __LOAD_H__
