#ifndef BASEDATAREADER_H
#define BASEDATAREADER_H
#include "definitions.h"
#include <vector>

class BaseDataReader
{
protected:
    std::vector< Interval > m_Intervals;
    ErrCodeRead m_eReadStatus;

public:
    virtual ~BaseDataReader() = default;

    virtual ErrCodeRead readData() = 0;
    virtual void parseData() = 0;
    ErrCodeRead getReadStatus();

    const std::vector< Interval >&
    getIntervals();
};

#endif // BASEDATAREADER_H
