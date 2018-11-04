#pragma once
#include <string>
#include "dataReader.h"
class DataReaderFromFile :
	public DataReader
{
	const std::string m_fileName;
	std::string m_Data;

public:

	DataReaderFromFile(const std::string fileName);
	virtual ~DataReaderFromFile();
	
	virtual const std::vector <Interval> & getIntervals()const override;
	virtual ErrCode readData() override;
	virtual void parseData() override;
};

