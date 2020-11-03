#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "ireader.h"
#include "View/iwriter.h"
#include "CLI.h"
#include "command_collection.h"
#include "Model/DNA_data_collection.h"
//#include "iDNA_accessor.h"
class Controller
{
public:
	Controller(IReader* reader, IWriter* writer);
	void systemInit();
	void systemShutDown();
	void setReader(IReader* reader);
	void setWriter(IWriter* writer);
	const DNADataCollection& getDNADataCollection()const;
private:
	IReader* m_reader;
	IWriter* m_writer;
	CLI m_CLI;
	CommandCollection m_cmdCollection;
	DNADataCollection m_DNADataCollection;
};


inline Controller::Controller(IReader* reader, IWriter* writer):m_reader(reader), m_writer(writer), m_CLI(*(new CLI)), m_cmdCollection(*(new CommandCollection)), m_DNADataCollection(*(new DNADataCollection))
{
	systemInit();
}
inline void Controller::systemInit()
{
	m_CLI.executeCommands(&m_cmdCollection, &m_DNADataCollection, m_reader, m_writer);
}
//inline void Controller::systemShutDown();
inline void Controller::setReader(IReader* reader)
{
	m_reader = reader;
}
inline void Controller::setWriter(IWriter* writer)
{
	m_writer = writer;
}
inline const DNADataCollection& Controller::getDNADataCollection()const
{
	return m_DNADataCollection;
}
	
#endif //__CONTROLLER_H__
