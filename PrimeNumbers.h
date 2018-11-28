#ifndef PRIMENUMBERS_H
#define PRIMENUMBERS_H
#include "BaseDataSaver.h"
#include "BaseDataReader.h"
#include <set>
#include <mutex>

struct dataToThread
{
    Interval m_Interval;
    std::mutex* m_pMutex;
    std::set< int >& m_PrimeNumbers;

    dataToThread(Interval interval, std::mutex* pMutex, std::set< int >& primeNumbers):m_Interval(interval), m_pMutex(pMutex), m_PrimeNumbers(primeNumbers){}
};

class PrimeNumbers
{
    std::set< int > m_primeNumbers;
    BaseDataSaver* m_pSaver;
    BaseDataReader* m_pReader;
    void threadFunction(dataToThread* pData);
    bool isPrimeNumber(int n);

public:
    PrimeNumbers();

    ErrCodeRead readData(BaseDataReader* pReader);
    void parseData();
    ErrCodeWrite saveData(BaseDataSaver* pSaver);
    void showData();
};

#endif // PRIMENUMBERS_H
