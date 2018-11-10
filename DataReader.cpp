#include "DataReader.h"

DataReader::~DataReader()
{

}

ErrCode DataReader::getReadStatus()
{
    return m_eReadStatus;
}

std::vector <Interval> DataReader::getIntervals()
{
    return m_Intervals;
}

