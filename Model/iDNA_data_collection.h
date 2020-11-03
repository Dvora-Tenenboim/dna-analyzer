#ifndef __IDNA_DATA_COLLECTION_H__
#define __IDNA_DATA_COLLECTION_H__

#include "DNA_data.h"

class IDNADataCollection
{
public:
	virtual ~IDNADataCollection(){};
	virtual void addDNAData(const DNAData& DNAD) = 0;
	virtual void removeDNAData(const DNAData& DNAD) = 0;
	virtual void removeDNAData(const std::string& name) = 0;
	virtual void removeDNAData(size_t id) = 0;
	virtual const DNAData& getDNAData(const std::string& name) = 0;
	virtual const DNAData& getDNAData(size_t id) = 0;
	virtual const DNAData& getDNAData(const DNASeq& DNAS) = 0;
};

#endif //__IDNA_DATA_COLLECTION_H__

