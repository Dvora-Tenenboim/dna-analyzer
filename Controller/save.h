#ifndef __SAVE_H__
#define __SAVE_H__ 

#include <iostream>
#include <vector>
#include "icommand.h"

class Save:public ICommand
{
public:
	/*virtual*/ std::string execute(const std::vector<std::string>& input, IDNADataCollection* DNADataCol) const;
};

#endif // __SAVE_H__
