#include "stdafx.h"
#include "dataReader.h"
#include <iostream>
#include <cstdio>

DataReader::DataReader():m_readStatus(ErrCode::READ_OK)
{
}

DataReader::~DataReader()
{
	
}


size_t DataReader::dataSize()
{
	return m_Intervals.size();
}

ErrCode DataReader::getReadingDataStatus()
{
	return m_readStatus;
}