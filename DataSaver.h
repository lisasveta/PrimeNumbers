#pragma once
#include <string>
#include <set>
#include "definitions.h"

class DataSaver
{

public:
	virtual ErrCode saveData(const std::set<int> numbers) const = 0;
	virtual ~DataSaver();
};

