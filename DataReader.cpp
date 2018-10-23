#include "stdafx.h"
#include "dataReader.h"
#include <iostream>
#include <cstdio>

DataReader::DataReader()
{
}

DataReader::~DataReader()
{
	std::cout << "DataReader::~DataReader() " << std::endl;
}

std::vector <Interval> DataReader::getIntervals()
{
	return m_Intervals;
}
