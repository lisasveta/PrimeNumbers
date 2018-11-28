#include "BaseDataReader.h"

ErrCodeRead BaseDataReader::getReadStatus()
{
    return m_eReadStatus;
}

const std::vector< Interval >&
BaseDataReader::getIntervals()
{
    return m_Intervals;
}

