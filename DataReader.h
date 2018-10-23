#pragma once
#include "definitions.h"
#include <vector>
class DataReader
{
	std::vector <Interval> m_Intervals;
	
public:
	DataReader();
	virtual ~DataReader();

	virtual std::vector <Interval> getIntervals() = 0;
};

