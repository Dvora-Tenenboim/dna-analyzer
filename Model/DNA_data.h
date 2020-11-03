#ifndef __DNA_DATA_H__
#define __DNA_DATA_H__

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "DNA_seq.h"

class DNAData
{
private:
	class DNAName
	{
	public:
		DNAName();
		DNAName(const std::string& name);
		const std::string& getNameAsString()const;

	private:
		std::string m_nameAsString;
		static size_t s_defaultNameCounter;
	};

	DNASeq m_DNASeq;
	DNAName m_name;
	size_t m_id;
	
	static size_t s_idCounter;

public:
	DNAData();//TODO without default ctor
	DNAData(const DNASeq& DNASequense);
	DNAData(const DNASeq& DNASequense, const std::string& name);
	const DNASeq& getDNASeq()const;
	const std::string& getNameAsString()const;
	size_t getId()const;
	std::string getIdAsString()const;
	
};

//--------------Auxilary functions-----------------//

inline std::string toString(size_t num)
{
	std::stringstream ss;
  	ss << num;
 	return ss.str();
}

//---------end of auxilary functions------------//
//-------Member functions of DNAData-------------//
inline DNAData::DNAData() : m_DNASeq("T"), m_name(), m_id(s_idCounter)
{}

inline DNAData::DNAData(const DNASeq& DNASequense) : m_DNASeq(DNASequense), m_name(DNAName("default")), m_id(s_idCounter++)
{}

inline DNAData::DNAData(const DNASeq& DNASequense, const std::string& name) : m_DNASeq(DNASequense), m_name(DNAName(name)), m_id(s_idCounter++)
{
	//TODO check if s_counter is less then max::size_t and allow use deleted id
}

inline const DNASeq& DNAData::getDNASeq()const
{
	return m_DNASeq;
}


inline const std::string& DNAData:: getNameAsString()const
{
	return m_name.getNameAsString();
}

inline size_t DNAData::getId()const
{
	return m_id;
}

inline std::string DNAData:: getIdAsString()const
{
	return toString(m_id);
}

//------End member functions of DNAData-------------//


//-------Member functions of DNAData::DNAName-------------//

inline DNAData::DNAName:: DNAName()
{
	//TODO check if s_defaultNameCounter is less then max::size_t and allow use deleted names
}

inline DNAData::DNAName :: DNAName(const std::string& name):m_nameAsString(name)
{
	//TODO check if name exist allready
	if (name == "default")
	{
		m_nameAsString = "seq";
		m_nameAsString += toString(s_defaultNameCounter);
		s_defaultNameCounter++;
	
	}
	//TODO check if name is NULL
}

inline const std::string& DNAData::DNAName:: getNameAsString()const
{
	return m_nameAsString;
}

//-------End member functions of DNAData::DNAName-------------//

#endif //__DNA_DATA_H__
