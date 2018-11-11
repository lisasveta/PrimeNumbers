﻿#include <iostream>
#include "DataReader.h"
#include "DataReaderFromXML.h"
#include "PrimeNumbers.h"
#include "DataSaverToXML.h"
//#include "definitions.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    PrimeNumbers prNumb;
    DataReaderFromXML reader("/home/ai/PrimeNumbers/intervals.xml");
    ErrCode er = prNumb.readData(&reader);
    if(READ_OK == er)
    {
        prNumb.parseData();
        prNumb.showData();
        DataSaverToXML saver("result.xml");
        ErrCode er = prNumb.saveData(&saver);
        std::cout << er << std::endl;
    }
    return 0;
}

