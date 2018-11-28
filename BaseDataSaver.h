#ifndef BASEDATASAVER_H
#define BASEDATASAVER_H
#include "definitions.h"
#include <iostream>

class BaseDataSaver
{
public:
    virtual ~BaseDataSaver() = default;

    virtual ErrCodeWrite saveData(const std::string& data)const = 0;
};

#endif // BASEDATASAVER_H
