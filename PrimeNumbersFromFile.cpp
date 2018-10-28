#include "stdafx.h"
#include "DataReader.h"
#include "DataReaderFromFile.h"
#include "DataSaver.h"
#include "DataSaverToFile.h"
#include <iostream>
#include <Windows.h>
#include <mutex>
#include <iostream>
#include "PrimeNumbersFromFile.h"


PrimeNumbersFromFile::PrimeNumbersFromFile()
{
}


PrimeNumbersFromFile::~PrimeNumbersFromFile()
{
}


void PrimeNumbersFromFile::addNumbersFromIntervals(std::vector<Interval> vc)
{
	HANDLE hMut = CreateMutexA(0, TRUE, "name"); //TRUE - main is a mutex owner

	dataToThread * pDataTh; //data struct for thread
	int nCountThreads = vc.size();
	HANDLE *pHand = new HANDLE[nCountThreads]; //create array for thread handles

	int threadInd = 0;
	std::vector<Interval>::iterator itEnd = vc.end();
	for (std::vector<Interval>::iterator it = vc.begin(); it != itEnd; ++it)
	{
		pDataTh = new dataToThread(&m_primeNumbers, { it->m_nBeg, it->m_nEnd }, &hMut); //create data struct for current thread
		pHand[threadInd] = CreateThread(NULL, 0, threadFunct, pDataTh, 0, 0);
		++threadInd;
	}

	std::cout << "Do you want release mutex?(y/n) ";
	char cAnswer;
	std::cin >> cAnswer;
	if (cAnswer == 'y')
		ReleaseMutex(hMut);

	WaitForMultipleObjects(nCountThreads, pHand, TRUE, INFINITE);

	for (int i = 0; i < nCountThreads; ++i)
		CloseHandle(pHand[i]);

	delete[] pHand;

	CloseHandle(hMut);

}
bool PrimeNumbersFromFile::isThisPrimeNumber(int num)
{
	bool bPrimeNumber = true;
	int maxDelimiter = num / 2;
	for (int i = 2; i < maxDelimiter; ++i)
		if (num % i == 0)
		{
			bPrimeNumber = false;
			break;
		}
	return bPrimeNumber;
}

DWORD PrimeNumbersFromFile::threadFunct(LPVOID lpParam)
{
	dataToThread *pData = (dataToThread*)lpParam;
	WaitForSingleObject(*(pData->m_phMut), INFINITE);
	DWORD dwId = GetCurrentThreadId(); // or std::this_thread::get_id()
	std::cout << "Thread #" << dwId << std::endl;

	for (int i = pData->interval.m_nBeg; i <= pData->interval.m_nEnd; ++i)
		if (isThisPrimeNumber(i))
			pData->m_pPrimeNumbers->insert(i);

	std::cout << "data: \n";
	std::set<int>::iterator itEnd = (pData->m_pPrimeNumbers)->end();
	for (std::set<int>::iterator it = (pData->m_pPrimeNumbers)->begin(); it != itEnd; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "*******************************************************************\n";
	ReleaseMutex(*(pData->m_phMut));
	delete pData;

	return 0;
}

ErrCode PrimeNumbersFromFile::getDataFromFile(const char *pFileName)
{
	
	ErrCode err = ErrCode::READ_OK;
	try {
		m_pReader = new DataReaderFromFile(pFileName);

		if (m_pReader->dataSize() > 0)
		{
			std::vector<Interval> intervals = m_pReader->getIntervals();
			addNumbersFromIntervals(intervals);
		}
		else
			err = m_pReader->getReadingDataStatus();

		delete m_pReader;
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "Allocation failed: " << e.what() << '\n';
	}
	return err;
}

void PrimeNumbersFromFile::showNumbers()
{
	std::set<int>::iterator itEnd = m_primeNumbers.end();
	for (std::set<int>::iterator it = m_primeNumbers.begin(); it != itEnd; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

ErrCode PrimeNumbersFromFile::saveToFile(const char *pFileName)
{
	ErrCode er = ErrCode::WRITE_OK;
	m_pSaver = new DataSaverToFile;
	if (nullptr != m_pSaver)
	{
		er = m_pSaver->saveData(pFileName, m_primeNumbers);
		delete m_pSaver;
	}

	return er;
}

