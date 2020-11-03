#ifndef __DNA_SEQUENCE_H__
#define __DNA_SEQUENCE_H__
#include <iostream>
#include <stdbool.h>
#include <cstring>
#include <string>
#include <stdexcept>    
#include "invalid_nucleotide.h"
#include "Controller/open_dna_file_error.h"
#include <fstream>
#include <vector>
class DNASeq
{
private:
	class Nucleotide
	{
	public:
		Nucleotide();
		Nucleotide(const char nucleotide);
		Nucleotide& operator=(const char nucleotide);
		char getNucleotide()const;
		operator char();
	private:
		char m_nucleotide;
	};	
	Nucleotide*  m_sequence;
	size_t m_length;

	void ctorInit(const char* sequence);
	DNASeq& assignmentOp(const char* sequence);
	void copy(const Nucleotide* src);
	void copy(const char* src);

public:
	DNASeq();
	DNASeq(const std::string& sequence);
	DNASeq(const char* sequence);
	DNASeq(const DNASeq& dnaSec);
	//DNASeq(std::ifstream file);
	~DNASeq();
	DNASeq& operator=(const DNASeq& dnaSec);
	DNASeq& operator=(const std::string& sequence);
	DNASeq& operator=(const char* dnaSec);
	const Nucleotide& operator[](const size_t i)const;
	Nucleotide& operator[](const size_t i);
	DNASeq getSlice(size_t ind1,size_t ind2)const;
	DNASeq getPaire()const;
	void writeToFile(const char* fileName)const;
	void readFromFile(const char* fileName);
	size_t findSubSequence(const DNASeq& dnaSeq,size_t pos)const;
	std::vector<size_t> findAll(const DNASeq& dnaSeq)const;
	std::vector<DNASeq> findConsensusSequences()const;
	size_t getSequenceLength()const;
	const Nucleotide* getSequence()const;
	std::string getAsString()const;
	friend std::ostream& operator<<(std::ostream& os ,const DNASeq& dnaSec);
	friend std::ostream& operator<<(std::ostream& os ,const Nucleotide& nucleotide);
	
	
};


/*global functions*/
bool isValid(const char nucleotide);
char paire(const char c);
inline bool operator==(const DNASeq& dnaSec1,const DNASeq& dnaSec2)
{
	size_t length1=dnaSec1.getSequenceLength();
	if(length1!=dnaSec2.getSequenceLength())
		return false;
	for(size_t i=0;i<length1;i++)
	{
		if((dnaSec1.getSequence()[i]).getNucleotide()!=(dnaSec2.getSequence()[i]).getNucleotide())
			return false;
	}
	return true;
}
inline bool operator!=(const DNASeq& dnaSec1,const DNASeq& dnaSec2)
{
	return !(dnaSec1 == dnaSec2);
}
inline std::ostream& operator<<(std::ostream& os ,const DNASeq::Nucleotide& nucleotide)
{
	os<<nucleotide.getNucleotide();
	return os;
}
inline std::ostream& operator<<(std::ostream& os ,const DNASeq& dnaSec)
{
	os<<dnaSec.getAsString();
	return os;
}
/*member functions of DNASeq class*/
inline void DNASeq::ctorInit(const char* sequence)
{
	m_sequence=new Nucleotide[m_length];
	try
	{
		copy(sequence);
	}
	catch(InvalidNucleotide& e)
	{
		delete[]m_sequence;
		throw;
	}
	
}
inline DNASeq& DNASeq::assignmentOp(const char* sequence)
{
	m_length=strlen(sequence);
	Nucleotide* tmp=m_sequence;
	m_sequence=new Nucleotide[m_length];
	try
	{
		copy(sequence);
	}
	catch(InvalidNucleotide& e)
	{
		delete[]m_sequence;
		throw;
	}
	delete[]tmp;
	return *this;
}
inline DNASeq::DNASeq():m_sequence(NULL),m_length(1)
{
	ctorInit("T");
}
inline DNASeq::DNASeq(const std::string& sequence):m_sequence(NULL),m_length(sequence.length())
{
	ctorInit(sequence.c_str());
}
inline DNASeq::DNASeq(const char* sequence):m_sequence(NULL),m_length(strlen(sequence))
{
	ctorInit(sequence);
}
inline DNASeq::DNASeq(const DNASeq& dnaSec)
{
	m_length=dnaSec.m_length;
	m_sequence=new Nucleotide[m_length];
	copy(dnaSec.m_sequence);
}
/*inline DNASeq::DNASeq(std::ifstream file)
{
	std::ifstream myFile
	std::string dnaStr;
    if (file.is_open())
	{
		while (file.good())
             getline(file, dnaStr);
        file.close();
	}
	else
		throw OpenDnaFileError();
    *this=DNASeq(dnaStr);
	
}*/
inline DNASeq& DNASeq::operator=(const DNASeq& dnaSec)
{
	m_length=dnaSec.m_length;
	Nucleotide* tmp=m_sequence;
	m_sequence=new Nucleotide[m_length];
	delete[]tmp;
	copy(dnaSec.m_sequence);
	return *this;
}
inline DNASeq& DNASeq::operator=(const std::string& sequence)
{
	return assignmentOp(sequence.c_str());
}
inline DNASeq& DNASeq::operator=(const char* sequence)
{
	return assignmentOp(sequence);
}
inline DNASeq::~DNASeq()
{
	delete[]m_sequence;
}
inline const DNASeq::Nucleotide& DNASeq::operator[](const size_t i)const
{
	if(i>=m_length)
		throw std::out_of_range("out_of_range:  the length of dna sequence is smaller then given index");
	return m_sequence[i];
	
}
inline DNASeq::Nucleotide& DNASeq::operator[](const size_t i)
{
	if(i>=m_length)
		throw std::out_of_range("out_of_range:  the length of dna sequence is smaller then given index");
	return m_sequence[i];
	
}
inline void DNASeq::writeToFile(const char* fileName)const
{
	std::ofstream myfile(fileName);
  	if (myfile.is_open())
  	{
    	myfile << getAsString() << std::endl;
    	myfile.close();
  	}
  	else
		throw OpenDnaFileError();
   
}
inline void DNASeq::readFromFile(const char* fileName)
{
	std::ifstream myfile(fileName);
	std::string tmpStr, dnaStr = "";
  	if (myfile.is_open())
  	{
    	while (myfile.good())
		{
			 getline(myfile, tmpStr);
			 dnaStr += tmpStr;
		}
        myfile.close();
  	}
  	else
	{
		throw OpenDnaFileError();
	}
	*this = DNASeq(dnaStr);
   
}
inline size_t DNASeq::getSequenceLength()const
{
	return m_length;
}

inline void DNASeq::copy(const char* src)
{
	for(size_t i=0;i<m_length;i++)
	{
		m_sequence[i]=src[i];
	}	
}
inline void DNASeq::copy(const Nucleotide* src)
{
	for(size_t i=0;i<m_length;i++)
	{
		m_sequence[i]=src[i];
	}	
}

inline const DNASeq::Nucleotide* DNASeq::getSequence()const
{
	return m_sequence;
}
inline std::string DNASeq::getAsString()const
{
	std::string dnaString;
	for(size_t i=0;i<m_length;i++)
	{
		dnaString+=(*this)[i].getNucleotide();
	}
	return dnaString;
}


/*member functions of Nucleotide class*/
inline DNASeq::Nucleotide::Nucleotide(){}
inline DNASeq::Nucleotide::Nucleotide(const char nucleotide):m_nucleotide(nucleotide)
{
	if(!isValid(nucleotide))
	{
		throw InvalidNucleotide();
	}
}
inline DNASeq::Nucleotide& DNASeq::Nucleotide::operator=(const char nucleotide)
{
	if(!isValid(nucleotide))
	{
		throw InvalidNucleotide();
	}
	m_nucleotide=nucleotide;
	return *this;
}

inline char DNASeq::Nucleotide::getNucleotide()const
{
	return m_nucleotide;
}
inline DNASeq::Nucleotide::operator char()
{
	return m_nucleotide;
}
#endif
