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
				pData = new char[fileSize]; // + 1 for 0 (EOF)?
				size_t nSize = fread_s(pData, fileSize, sizeof(char), fileSize, pFile);
				
				//check real size of readed data
				if (nSize < fileSize)
				{
					int nRemainingSize;
					int nPortionSize = 0;
					do
					{
						nRemainingSize = fileSize - nSize;
						nPortionSize = fread_s(pData + nSize, nRemainingSize, sizeof(char), nRemainingSize, pFile);
						nSize += nPortionSize;
					} while (nSize < fileSize);
				}

				if (nSize > 0)
				{
					parseIntervalsFromFile();
				}
			}
			catch (const std::bad_alloc& e)
			{
				std::cout << "Allocation failed: " << e.what() << '\n';
			}
		}
		fclose(pFile);
	}

}

DataReaderFromFile::~DataReaderFromFile()
{
	if (pData != nullptr)
		delete[] pData;
}


void DataReaderFromFile::parseIntervalsFromFile()
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