#include "stdafx.h"
#include "dataReader.h"

DataReader::DataReader():m_eReadStatus(ErrCode::READ_OK)
{
}
DataReader::~DataReader()
{
}

ErrCode DataReader::getReadingDataStatus() const
{
	return m_eReadStatus;
}