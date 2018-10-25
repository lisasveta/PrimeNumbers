#pragma once
#include "dataReader.h"
class DataReaderFromFile :
	public DataReader
{
	char *pData;
	void parseIntervalsFromFile();

public:
	DataReaderFromFile(const char * pFileName);
	~DataReaderFromFile();

	virtual std::vector <Interval> getIntervals();
};

