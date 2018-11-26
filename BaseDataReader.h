#ifndef DATAREADER_H
#define DATAREADER_H
#include "definitions.h"
#include <vector>

class DataReader
{
protected:
    std::vector <Interval> m_Intervals;
    ErrCode m_eReadStatus;

public:
    virtual ~DataReader() = default;

    virtual ErrCode readData() = 0;
    virtual void parseData() = 0;
    ErrCode getReadStatus();
    const std::vector< Interval >& getIntervals();
};

#endif // DATAREADER_H
