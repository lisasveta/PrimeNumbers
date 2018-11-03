#include "stdafx.h"
#include "DataSaverToFile.h"
#include "PrimeNumbers.h"

#include <iostream>
#include <cstdio>
#include <string>

DataSaverToFile::DataSaverToFile()
{
}

ErrCode DataSaverToFile::saveData(const std::string fileName, std::set<int> numbers) const
{
	ErrCode err = ErrCode::m_eWRITE_OK;
	
	std::string strDataToFile;
	strDataToFile.append("<root>\n<primes>\n");

	std::set<int>::iterator itEnd = numbers.end();
	for (std::set<int>::iterator it = numbers.begin(); it != itEnd; ++it)
	{
		strDataToFile.append(std::to_string(*it));
		strDataToFile.append(" ");
	}
	strDataToFile.append("\n</primes>\n</root>");

	//std::cout << "---------------------------------\n" << strDataToFile.data() << std::endl;

	FILE *pFile;
	errno_t errCode = fopen_s(&pFile, fileName.data(), "wb");
	if (EACCES == errCode)
	{
		err = ErrCode::m_eFILE_NO_ACCESS;
	}
	else if (0 == errCode)
	{
		size_t allDataSize = strDataToFile.size();
		size_t writingDataSize = fwrite(strDataToFile.data(), sizeof(char), strDataToFile.size(), pFile);
		size_t nextPartSize;
		while (writingDataSize < allDataSize) //for partial reading
		{
			nextPartSize = allDataSize - writingDataSize;
			writingDataSize += fwrite(strDataToFile.data() + writingDataSize, sizeof(char), nextPartSize, pFile);
		}
		fclose(pFile);
	}
	return err;
}


DataSaverToFile::~DataSaverToFile()
{
}
