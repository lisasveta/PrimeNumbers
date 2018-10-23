#include "stdafx.h"
#include "DataSaverToFile.h"
#include "PrimeNumbers.h"

#include <iostream>
#include <cstdio>

DataSaverToFile::DataSaverToFile()
{
}
//to do: return  error code
FileErrors DataSaverToFile::saveData(const char * pFileName, std::set<int> numbers)
{
	//creating temporary buffer for data
	try
	{
		int nCountNumbers = numbers.size();
		int nBuffSize = nCountNumbers * sizeof(int) + nCountNumbers + 40;
		char *pData = new char[nBuffSize];

		int ind = 0, nShift;
		std::set<int>::iterator itEnd = numbers.end();
		sprintf_s(pData, 20, "<root>\n<primes>\n");
		ind = 22;
		for (std::set<int>::iterator it = numbers.begin(); it != itEnd; ++it)
		{
			sprintf_s(pData + ind, sizeof(int) + 1, "%d ", *it); // 1 for space in end
			nShift = strlen(pData);
			ind = nShift;
		}
		sprintf_s(pData + ind, 20, "\n</primes>\n</root>");

		//std::cout << " " << pData << std::endl;

		FILE *pFile;
		errno_t errCode = fopen_s(&pFile, pFileName, "wb"); // ? mode
		if (0 == errCode)
		{
			size_t dataSize = fwrite(pData, sizeof(char), strlen(pData), pFile);
			//to do: check for complete writing
			fclose(pFile);
		}

		delete[]pData;
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "Allocation failed: " << e.what() << '\n';
	}
	return WRITE_OK;
}


DataSaverToFile::~DataSaverToFile()
{
}
