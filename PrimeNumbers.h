#pragma once
#include <set>
#include <vector>
#include "definitions.h"
#include "windows.h"
#include <mutex>

class DataReader;
class DataSaver;

class PrimeNumbers
{
	struct dataToThread
	{
		std::set<int> * m_pPrimeNumbers;
		Interval m_Interval;
		std::mutex *pSet_mutex;
		dataToThread(std::set<int> *numbers, Interval interval, std::mutex *pMut) :m_pPrimeNumbers(numbers), m_Interval(interval), pSet_mutex(pMut) {}
	};

	std::set<int> m_primeNumbers;
	DataReader *m_pReader;
	DataSaver *m_pSaver;

	void addNumbersFromIntervals(const std::vector<Interval> vc);
	static bool isThisPrimeNumber(const int num);
	
public:
	PrimeNumbers();
	
	ErrCode readData(DataReader *pReader);
	void parseData();
	void showNumbers() const;
	ErrCode saveData(DataSaver *pSaver);
	bool empty() const;
	static void threadFunction(dataToThread *pData);
	
};

