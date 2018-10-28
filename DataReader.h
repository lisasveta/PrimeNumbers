#pragma once
#include "definitions.h"
#include <vector>

class DataReader
{
protected:
	std::vector <Interval> m_Intervals;
	virtual ErrCode readData() = 0;
	ErrCode m_readStatus;

public:
	DataReader();
	virtual ~DataReader();
		
	virtual std::vector <Interval> getIntervals() = 0;
	size_t dataSize();
	ErrCode getReadingDataStatus();
};

