#pragma once
#include <string>
#include "DataSaver.h"
class DataSaverToFile :
	public DataSaver
{
public:
	DataSaverToFile();
	~DataSaverToFile();

	virtual ErrCode saveData(const std::string fileName, const std::set<int> numbers)const override;
};

