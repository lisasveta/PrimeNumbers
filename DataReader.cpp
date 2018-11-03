#include "stdafx.h"
#include "dataReader.h"
#include <iostream>
#include <cstdio>

DataReader::DataReader():m_readStatus(ErrCode::m_eREAD_OK)
{
}

DataReader::~DataReader()
{
	
}


size_t DataReader::getDataSize() const
{
	return m_Intervals.size();
}

ErrCode DataReader::getReadingDataStatus() const
{
	return m_readStatus;
}