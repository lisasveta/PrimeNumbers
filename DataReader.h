#pragma once
#include "definitions.h"
#include <vector>

class DataReader
{
protected:
	std::vector <Interval> m_Intervals;
	ErrCode m_eReadStatus;

public:
	DataReader();
	virtual ~DataReader();
		
	virtual const std::vector <Interval> & getIntervals() const = 0;
	virtual ErrCode readData() = 0;
	virtual void parseData() = 0;
	ErrCode getReadingDataStatus() const;
};

