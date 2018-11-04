#pragma once
#include <string>
#include "DataSaver.h"
class DataSaverToFile :
	public DataSaver
{
	const std::string m_fileName;
public:
	DataSaverToFile(const std::string fileName);
	virtual ~DataSaverToFile();

	virtual ErrCode saveData(const std::set<int> numbers)const override;
};

