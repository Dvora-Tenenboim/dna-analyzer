#ifndef __NEW_H__
#define __NEW_H__ 

#include "icommand.h"

class New:public ICommand
{
public:
	/*virtual*/ std::string execute(const std::vector<std::string>& input, IDNADataCollection* DNADataCol) const;
};

#endif // __NEW_H__
