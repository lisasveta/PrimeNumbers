#ifndef DATASAVER_H
#define DATASAVER_H
#include "definitions.h"

class DataSaver
{
public:
    virtual ~DataSaver();

    virtual ErrCode saveData(const std::string data)const = 0;
};

#endif // DATASAVER_H
