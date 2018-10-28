#pragma once
#include "dataReader.h"
class DataReaderFromFile :
	public DataReader
{
	const char *m_pFileName;
	char *pData;

	void parseIntervalsFromFile();
	

public:

	DataReaderFromFile(const char * pFileName);
	~DataReaderFromFile();

	virtual std::vector <Interval> getIntervals();
	virtual ErrCode readData();
};

