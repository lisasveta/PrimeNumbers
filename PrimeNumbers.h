#pragma once
#include <set>
#include <vector>
#include "definitions.h"
#include "windows.h"

class DataReader;
class DataSaver;

class PrimeNumbers
{
	struct dataToThread
	{
		std::set<int> * m_pPrimeNumbers;
		Interval interval;
		//add for synchronization
		HANDLE * m_phMut; //mutex's HANDLE send as a pointer

		dataToThread(std::set<int> *numbers, Interval interval, HANDLE *phMut):m_pPrimeNumbers(numbers), interval(interval), m_phMut(phMut) {}
	};

	std::set<int> m_primeNumbers;
	DataReader *p_mReader;
	DataSaver *p_mSaver;

	void addNumbersFromIntervals(std::vector<Interval> vc);
	static bool isThisPrimeNumber(int num);
	static DWORD WINAPI threadFunct(LPVOID lpParam);

public:
	PrimeNumbers();
	~PrimeNumbers();

	void getDataFromFile(const char *pFileName);
	void showNumbers();
	void saveToFile(const char *pFileName);
	
};

