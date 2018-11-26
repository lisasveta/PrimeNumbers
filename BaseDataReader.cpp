#include "DataReader.h"

ErrCode DataReader::getReadStatus()
{
    return m_eReadStatus;
}

const std::vector< Interval >& DataReader::getIntervals()
{
    return m_Intervals;
}

