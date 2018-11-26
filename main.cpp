﻿#include <iostream>
#include "DataReader.h"
#include "DataReaderFromXML.h"
#include "PrimeNumbers.h"
#include "DataSaverToXML.h"
#include <sstream>

int main()
{
    std::stringstream ss("somefirstnum 45 theanothenumber 67 anotherintnumber");
    char str1[100], str2[100];
    int nNum1, nNum2;
    ss >> str1 >> nNum1 >> str2 >> nNum2;
    std::cout << str1 << std::endl << nNum1 << std::endl << str2 << std::endl << nNum2 << std::endl;

    return 0;
    PrimeNumbers prNumb;
    DataReaderFromXML reader;
    reader.setFileName("/home/ai/PrimeNumbers/intervals.xml");
    ErrCode er = prNumb.readData(&reader);
    if(READ_OK == er)
    {
        prNumb.parseData();
        prNumb.showData();
        DataSaverToXML saver("result.xml");
        ErrCode er = prNumb.saveData(&saver);
        switch(er)
        {
        case WRITE_FAILED:
            std::cout << "error: file was fail in saving" << std::endl;
            break;
        case WRITE_OK:
            std::cout << "file was saved successfuly" << std::endl;
            break;
        }
        std::cout << er << std::endl;
    }
    else
    {
        switch(er)
        {
        case READ_FAILED:
            std::cout << "error: file was fail in reading" << std::endl;
            break;
        case FILE_NOT_EXIST:
            std::cout << "error: file don't exist" << std::endl;
            break;
        case FILE_NO_ACCESS:
            std::cout << "error: no access to file" << std::endl;
            break;
        case BAD_ALLOC:
            std::cout << "error: bad alloc" << std::endl;
            break;
        default:
            std::cout << "error: undefined error" << std::endl;
            break;
        }
    }
    return 0;
}

