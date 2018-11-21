#include <iostream>
#include "DataReader.h"
#include "DataReaderFromXML.h"
#include "PrimeNumbers.h"
#include "DataSaverToXML.h"

int main()
{
    PrimeNumbers prNumb;
    DataReaderFromXML reader("/home/ai/PrimeNumbers/intervals.xml");
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

