#pragma once
#include <set>
#include "definitions.h"

class DataSaver
{
public:
	DataSaver();
	~DataSaver();

	//to do: return  error code
	virtual FileErrors saveData(const char * pFileName, std::set<int> numbers) = 0;
};

