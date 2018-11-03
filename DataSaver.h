#pragma once
#include <string>
#include <set>
#include "definitions.h"

class DataSaver
{
public:
	DataSaver();
	~DataSaver();

	virtual ErrCode saveData(const std::string fileName, const std::set<int> numbers) const = 0;
};

