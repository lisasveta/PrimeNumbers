#include "stdafx.h"
#include "DataReaderFromFile.h"
#include <iostream>

DataReaderFromFile::DataReaderFromFile(const char * pFileName)
{

	FILE *pFile;
	errno_t errCode = fopen_s(&pFile, pFileName, "rb");
	errno_t f = ENOENT;
	if (0 == errCode)
	{
		int t = fseek(pFile, 0L, SEEK_END);
		long fileSize = ftell(pFile);
		if (fileSize > 0)
		{
			fseek(pFile, 0L, SEEK_SET);

			try {
				pData = new char[fileSize]; // + 1 for 0
				size_t nSize = fread_s(pData, fileSize, sizeof(char), fileSize, pFile);
				//to do: check readed data size and all amount of data
				if (nSize > 0)
				{
					//call function for parsing data from file
					parseIntervalsFromData();
				}
			}
			catch (const std::bad_alloc& e)
			{
				std::cout << "Allocation failed: " << e.what() << '\n';
			}
			//to do : create while circle for reading in portions
		}
		fclose(pFile);
	}

}

DataReaderFromFile::~DataReaderFromFile()
{
	std::cout << "DataReaderFromFile::~DataReaderFromFile() " << std::endl;
	if (pData != nullptr)
		delete[] pData;
}


void DataReaderFromFile::parseIntervalsFromData()
{
	int nCounter = 0;
	char *pInterval = pData;
	char *pLow, *pHigh;
	int nBeg, nEnd;

	while (pInterval = std::strstr(pInterval, "<interval>"))
	{
		pLow = std::strstr(pInterval, "<low>");
		pLow += 5;
		nBeg = std::atoi(pLow);
		pHigh = std::strstr(pInterval, "<high>");
		pHigh += 6;
		nEnd = std::atoi(pHigh);
		if (nBeg < nEnd)
			m_Intervals.push_back({ nBeg, nEnd });

		pInterval++;
	}

}

std::vector <Interval> DataReaderFromFile::getIntervals()
{
	return m_Intervals;
}