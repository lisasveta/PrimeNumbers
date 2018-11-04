#include "stdafx.h"
#include "dataReader.h"
#include <cstdio>

DataReader::DataReader():m_eReadStatus(ErrCode::READ_OK)
{
}

ErrCode DataReader::getReadingDataStatus() const
{
	return m_eReadStatus;
}