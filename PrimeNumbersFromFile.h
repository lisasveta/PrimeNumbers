#pragma once
#include <set>
#include <vector>
#include "definitions.h"
#include "windows.h"

class DataReader;
class DataSaver;

class PrimeNumbersFromFile
{
	struct dataToThread
	{
		std::set<int> * m_pPrimeNumbers;
		Interval m_Interval;
		//add for synchronization
		HANDLE * m_phMut; //mutex's HANDLE send as a pointer

		dataToThread(std::set<int> *numbers, Interval interval, HANDLE *phMut) :m_pPrimeNumbers(numbers), m_Interval(interval), m_phMut(phMut) {}
	};

	std::set<int> m_primeNumbers;
	DataReader *m_pReader;
	DataSaver *m_pSaver;

	void addNumbersFromIntervals(const std::vector<Interval> vc);
	static bool isThisPrimeNumber(const int num);
	static DWORD WINAPI threadFunct(LPVOID lpParam);


public:
	PrimeNumbersFromFile();
	~PrimeNumbersFromFile();

	ErrCode getDataFromFile(const char *pFileName);
	void showNumbers() const;
	ErrCode saveToFile(const char *pFileName);
	
};

