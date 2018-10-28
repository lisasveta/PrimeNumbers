#pragma once
#include "DataSaver.h"
class DataSaverToFile :
	public DataSaver
{
public:
	DataSaverToFile();
	~DataSaverToFile();

	virtual ErrCode saveData(const char * pFileName, std::set<int> numbers);
};

