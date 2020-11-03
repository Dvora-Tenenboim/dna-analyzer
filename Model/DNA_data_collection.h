#ifndef __DNA_DATA_COLLECTION_H__
#define __DNA_DATA_COLLECTION_H__

#include <iostream>
#include <map>
#include "iDNA_data_collection.h"

class DNADataCollection:public IDNADataCollection
{
public:
	DNADataCollection();
	void addDNAData(const DNAData& DNAD);
	void removeDNAData(const DNAData& DNAD);
	void removeDNAData(const std::string& name);
	void removeDNAData(size_t id);
	const DNAData& getDNAData(const std::string& name);
	const DNAData& getDNAData(size_t id);
	const DNAData& getDNAData(const DNASeq& DNAS);
private:
	std::map<std::string, size_t> m_namesMap;
	std::map<size_t, DNAData> m_idsMap;
};

//-------Member functions of DNADataCollection-------------//

inline DNADataCollection::DNADataCollection(){}

inline void DNADataCollection::addDNAData(const DNAData& DNAD)
{
	std::string name = DNAD.getNameAsString();
	size_t id = DNAD.getId();
	m_namesMap.insert( std::pair<std::string, size_t>(name, id) );
	m_idsMap.insert(std::pair<size_t, DNAData> (id, DNAD) );
}
inline void DNADataCollection::removeDNAData(const DNAData& DNAD)
{
	m_namesMap.erase(DNAD.getNameAsString());
	m_idsMap.erase(DNAD.getId());
}
inline void DNADataCollection::removeDNAData(const std::string& name)
{
	removeDNAData(getDNAData(name));
}
inline void DNADataCollection::removeDNAData(size_t id)
{
	removeDNAData(getDNAData(id));
}
inline const DNAData& DNADataCollection::getDNAData(const std::string& name)
{
	return m_idsMap[m_namesMap[name]];
}
inline const DNAData& DNADataCollection::getDNAData(size_t id)
{
	return m_idsMap[id];
}

inline const DNAData& DNADataCollection::getDNAData(const DNASeq& DNAS)
{
	std::map<size_t, DNAData>::const_iterator it = m_idsMap.begin();
	for (; it != m_idsMap.end(); ++it)
	{
  		if ( (it->second).getDNASeq() == DNAS)
  		{
  			return it->second;
  		}
	} 
	return it->second;
}

//------End member functions of DNADataCollection-------------//

#endif // __DNA_DATA_COLLECTION_H__
