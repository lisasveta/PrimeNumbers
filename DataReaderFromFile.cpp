#include "stdafx.h"
#include "DataReaderFromFile.h"

DataReaderFromFile::DataReaderFromFile(const std::string fileName):m_fileName(fileName)
{
}
DataReaderFromFile::~DataReaderFromFile()
{
}

const std::vector <Interval> & DataReaderFromFile::getIntervals() const
{
	return m_Intervals;
}

ErrCode DataReaderFromFile::readData()
{
	m_eReadStatus = ErrCode::READ_OK;

	FILE *pFile;
	errno_t errCode = fopen_s(&pFile, m_fileName.data(), "rb");
	if (ENOENT == errCode)
	{
		m_eReadStatus = ErrCode::FILE_NOT_EXIST;
	}
	else if (EACCES == errCode)
	{
		m_eReadStatus = ErrCode::FILE_NO_ACCESS;
	}
	else if (0 == errCode)
	{
		int t = fseek(pFile, 0L, SEEK_END);
		long fileSize = ftell(pFile);
		if (fileSize > 0)
		{
			fseek(pFile, 0L, SEEK_SET);
			char *pData = nullptr;
			try
			{
				pData = new char[fileSize]; // + 1 for 0 (EOF)?
			}
			catch (const std::bad_alloc & e)
			{
				std::cout << "Allocation failed: " << e.what() << '\n';
				m_eReadStatus = ErrCode::MEM_BAD_ALLOC;
			}
			
			if (ErrCode::MEM_BAD_ALLOC != m_eReadStatus)
			{
				long nSize = fread_s(pData, fileSize, sizeof(char), fileSize, pFile);

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
					} 
					while (nSize < fileSize);
				}
				m_Data.append(pData);
				delete[]pData;

			}
			
		}
		else
		{
			m_eReadStatus = ErrCode::FILE_IS_EMPTY;
		}
		fclose(pFile);
	}
	return m_eReadStatus;
}

void DataReaderFromFile::parseData()
{
	if (m_Data.size() > 0)
	{
		int nBeg(0), nEnd(0);
		size_t pos = m_Data.find("<interval>"), posLow(0), posHigh(0);

		while (pos > 0)
		{
			posLow = m_Data.find("<low>", pos);
			nBeg = std::atoi(m_Data.data() + posLow + strlen("<low>"));
			posHigh = m_Data.find("<high>", posLow);
			nEnd = std::atoi(m_Data.data() + posHigh + strlen("<high>"));
			if (nBeg < nEnd)
			{
				m_Intervals.push_back({ nBeg, nEnd });
			}
			pos = m_Data.find("<interval>", posHigh);
			if (std::string::npos == pos)
			{
				break;
			}
		}
	}
}

