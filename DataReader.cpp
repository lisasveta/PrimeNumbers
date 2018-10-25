#include "stdafx.h"
#include "dataReader.h"
#include <iostream>
#include <cstdio>

DataReader::DataReader()
{
}

DataReader::~DataReader()
{
	
}

std::vector <Interval> DataReader::getIntervals()
{
	return m_Intervals;
}
