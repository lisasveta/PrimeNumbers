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
		Interval m_Interval;
		HANDLE * m_phMut;

		dataToThread(std::set<int> *numbers, Interval interval, HANDLE *phMut) :m_pPrimeNumbers(numbers), m_Interval(interval), m_phMut(phMut) {}
	};

	std::set<int> m_primeNumbers;
	DataReader *m_pReader;
	DataSaver *m_pSaver;

	void addNumbersFromIntervals(const std::vector<Interval> vc);
	static bool isThisPrimeNumber(const int num);
	static DWORD WINAPI threadFunct(LPVOID lpParam);


public:
	PrimeNumbers();
	
	ErrCode readData(DataReader *pReader);
	void parseData();
	void showNumbers() const;
	ErrCode saveData(DataSaver *pSaver);
	bool empty() const;
	
};

