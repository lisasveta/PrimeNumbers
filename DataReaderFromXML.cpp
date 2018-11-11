#include "DataReaderFromXML.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include "definitions.h"

DataReaderFromXML::DataReaderFromXML(std::string fileName):m_fileName(fileName)
{
}

DataReaderFromXML::~DataReaderFromXML()
{
}

ErrCode DataReaderFromXML::readData()
{
    m_eReadStatus = READ_OK;

    FILE *pFile = fopen(m_fileName.data(), "r");
    if(pFile != nullptr)
    {
        fseek(pFile, 0L, SEEK_END);
        size_t lFileSize = static_cast<unsigned long> (ftell(pFile));
        char *pData(nullptr);
        try
        {
            pData = new char[lFileSize];
        }
        catch(const std::bad_alloc e)
        {
            std::cout << "bad alloc! " << e.what() << std::endl;
            m_eReadStatus = BAD_ALLOC;
        }

        if(nullptr != pData)
        {
            fseek(pFile, 0L, SEEK_SET);
            size_t dataSize = fread(pData, sizeof(char), lFileSize, pFile);
            //reading by portion
            while(dataSize < lFileSize)
            {
                dataSize += fread(pData + dataSize, sizeof(char), lFileSize - dataSize, pFile);
                std::cout << "reading data from file by portion" << std::endl;
            }
            if(dataSize != 0)
            {
                m_DataFromFile.append(pData);
                delete [] pData;
            }
        }
        fclose(pFile);

    }
    else
    {
        m_eReadStatus = READ_FAILED;
    }

    return m_eReadStatus;
}

void DataReaderFromXML::parseData()
{
    if(READ_OK == m_eReadStatus)
    {
        size_t pos = m_DataFromFile.find("<intervals>");
        if(pos != 0)
        {
            size_t posLow(0), posHigh(0);
            size_t offsetLow = std::string("<low>").size();
            size_t offsetHigh = std::string("<high>").size();
            Interval curInterval;

            pos = m_DataFromFile.find("<interval>");
            while(pos != std::string::npos){
                posLow = m_DataFromFile.find("<low>", pos);
                posLow += offsetLow;
                curInterval.m_nBeg = stoi(m_DataFromFile.substr(posLow));
                posHigh = m_DataFromFile.find("<high>", pos);
                posHigh += offsetHigh;
                curInterval.m_nEnd = stoi(m_DataFromFile.substr(posHigh));
                if(curInterval.m_nBeg < curInterval.m_nEnd)
                {
                    m_Intervals.push_back(curInterval);
                }
                pos = m_DataFromFile.find("<interval>", posHigh);
            }
        }
    }
}
