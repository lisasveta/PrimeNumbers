#include "stdafx.h"
#include "DataSaverToFile.h"
#include "PrimeNumbers.h"

#include <iostream>
#include <cstdio>

DataSaverToFile::DataSaverToFile()
{
}

ErrCode DataSaverToFile::saveData(const char * pFileName, std::set<int> numbers)
{
	ErrCode err = ErrCode::WRITE_OK;
	
	try
	{
		int nCountNumbers = numbers.size();
		//calculating size for buffer to compound data for saving
		//nCountNumbers * sizeof(int) - size in bytes for all numbers from set
		// + nCountNumbers - for spaces between them 
		// + 40 for tags  "<root>\n<primes>\n" and "\n</primes>\n</root>"
		int nBuffSize = nCountNumbers * sizeof(int) + nCountNumbers + 40;
		char *pData = new char[nBuffSize];

		int ind = 0, nShift;
		std::set<int>::iterator itEnd = numbers.end();
		sprintf_s(pData, 20, "<root>\n<primes>\n");
		ind = 22;
		for (std::set<int>::iterator it = numbers.begin(); it != itEnd; ++it)
		{
			sprintf_s(pData + ind, sizeof(int) + 1, "%d ", *it); // 1 for space to the end
			nShift = strlen(pData);
			ind = nShift;
		}
		sprintf_s(pData + ind, 20, "\n</primes>\n</root>");

		//std::cout << " " << pData << std::endl;

		FILE *pFile;
		errno_t errCode = fopen_s(&pFile, pFileName, "wb");
		if (EACCES == errCode)
			err = ErrCode::FILE_NO_ACCESS;
		else if (0 == errCode)
		{
			size_t allDataSize = strlen(pData);
			size_t writingDataSize = fwrite(pData, sizeof(char), allDataSize, pFile);
			//to do: check for complete writing
			
			size_t nextPartSize;
			while (writingDataSize < allDataSize)
			{
				nextPartSize = allDataSize - writingDataSize;
				writingDataSize += fwrite(pData + writingDataSize, sizeof(char), nextPartSize, pFile);
			}
			
			fclose(pFile);
		}

		delete[]pData;
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "Allocation failed: " << e.what() << '\n';
		err = ErrCode::WRITE_FAILED;
	}
	return err;
}


DataSaverToFile::~DataSaverToFile()
{
}
