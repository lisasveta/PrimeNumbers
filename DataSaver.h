#ifndef DATASAVER_H
#define DATASAVER_H
#include "definitions.h"
#include <iostream>

class DataSaver
{
public:
    virtual ~DataSaver() = default;

    virtual ErrCode saveData(const std::string data)const = 0;
};

#endif // DATASAVER_H
