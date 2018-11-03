#pragma once
#include <string>
#include "dataReader.h"
class DataReaderFromFile :
	public DataReader
{
	const std::string m_fileName;
	std::string m_Data;

	void parseIntervalsFromFile();

public:

	DataReaderFromFile(const std::string fileName);
	~DataReaderFromFile();

	virtual const std::vector <Interval> & getIntervals()const override;
	virtual ErrCode readData() override;
};

