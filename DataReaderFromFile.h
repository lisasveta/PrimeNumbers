#pragma once
#include "dataReader.h"
class DataReaderFromFile :
	public DataReader
{
	char *pData;
	std::vector <Interval> m_Intervals;
	void parseIntervalsFromData();


public:
	DataReaderFromFile(const char * pFileName);
	~DataReaderFromFile();

	virtual std::vector <Interval> getIntervals();
};

