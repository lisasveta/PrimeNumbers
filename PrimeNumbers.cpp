#include "PrimeNumbers.h"
#include <thread>

PrimeNumbers::PrimeNumbers():m_pSaver(nullptr), m_pReader(nullptr)
{
}

PrimeNumbers::~PrimeNumbers()
{
}

bool PrimeNumbers::isPrimeNumber(int n)
{
    bool bPrime = true;
    int nMaxDelimiter = n/2;
    for(int i = 2; i < nMaxDelimiter; ++i)
    {
        if(n % nMaxDelimiter == 0)
        {
            bPrime = false;
            break;
        }
    }
    return bPrime;
}

void PrimeNumbers::threadFunction(dataToThread *pData)
{
    std::lock_guard<std::mutex> guard(*pData->m_pMutex);
    for(int i = pData->m_Interval.m_nBeg; i <= pData->m_Interval.m_nEnd; ++i)
    {
        if(isPrimeNumber(i))
        {
            m_primeNumbers.insert(i);
        }
    }
    delete pData;
}

ErrCode PrimeNumbers::readData(DataReader *pReader)
{
    m_pReader = pReader;
    ErrCode err = m_pReader->readData();
    return err;
}

void PrimeNumbers::parseData()
{
    if(READ_OK == m_pReader->getReadStatus())
    {
       m_pReader->parseData();
       std::vector<Interval> data = m_pReader->getIntervals();
       unsigned nIntervalsNumber = static_cast<unsigned>(data.size());
       if(0 != nIntervalsNumber)
       {
           std::mutex mut;
           std::thread **pThreads = new std::thread *[nIntervalsNumber];
           for(unsigned i = 0; i < nIntervalsNumber; ++i)
           {
                dataToThread  *pDataToThread = new dataToThread(data[i], &mut, m_primeNumbers);
                pThreads[i] = new std::thread(&PrimeNumbers::threadFunction, this, pDataToThread);

           }
           for(unsigned i = 0; i < nIntervalsNumber; ++i)
           {
               pThreads[i]->join();
           }
           std::cout << "All threads where ending." << std::endl;
           for(unsigned i = 0; i < nIntervalsNumber; ++i)
           {
               delete pThreads[i];
           }
           delete []pThreads;
       }
    }
}

ErrCode PrimeNumbers::saveData(DataSaver *pSaver)
{
    ErrCode err = WRITE_OK;
    m_pSaver = pSaver;
    std::string dataToSave;
    dataToSave.append("<root>\n<primes>");
    std::set<int>::iterator itBeg = m_primeNumbers.begin();
    std::set<int>::iterator itEnd = m_primeNumbers.end();
    for(std::set<int>::iterator it = itBeg; it != itEnd; ++it)
    {
        dataToSave.append(std::to_string(*it));
        dataToSave.append(" ");
    }
    dataToSave.append("</primes>\n</root>");
    std::cout << dataToSave << std::endl;
    err = m_pSaver->saveData(dataToSave);
    return err;
}

std::set<int> PrimeNumbers::getData()const
{
    return m_primeNumbers;
}
void PrimeNumbers::showData()
{
    std::set<int>::iterator itBeg = m_primeNumbers.begin();
    std::set<int>::iterator itEnd = m_primeNumbers.end();
    for(std::set<int>::iterator it = itBeg; it != itEnd; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
