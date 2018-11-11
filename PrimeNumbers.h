#ifndef PRIMENUMBERS_H
#define PRIMENUMBERS_H
#include "DataSaver.h"
#include "DataReader.h"
#include <set>
#include <mutex>

struct dataToThread
{
    Interval m_Interval;
    std::mutex * m_pMutex;
    std::set<int> & m_PrimeNumbers;

    dataToThread(Interval interval, std::mutex *pMutex, std::set<int>& primeNumbers):m_Interval(interval), m_pMutex(pMutex), m_PrimeNumbers(primeNumbers){}
};

class PrimeNumbers
{
    std::set<int> m_primeNumbers;
    DataSaver * m_pSaver;
    DataReader * m_pReader;
    void threadFunction(dataToThread *pData);
    bool isPrimeNumber(int n);

public:
    PrimeNumbers();
    ~PrimeNumbers();

    ErrCode readData(DataReader *pReader);
    void parseData();
    ErrCode saveData(DataSaver *pSaver);
    std::set<int> getData()const;
    void showData();
};

#endif // PRIMENUMBERS_H
