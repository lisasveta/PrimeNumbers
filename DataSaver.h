#pragma once
#include <set>
#include "definitions.h"

class DataSaver
{
public:
	DataSaver();
	~DataSaver();

	virtual ErrCode saveData(const char * pFileName, std::set<int> numbers) = 0;
};

