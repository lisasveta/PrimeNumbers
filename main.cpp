#include <iostream>
#include "BaseDataReader.h"
#include "DataReaderFromXML.h"
#include "PrimeNumbers.h"
#include "DataSaverToXML.h"
#include <string>

int main()
{
    PrimeNumbers prNumb;
    //menu
    int nChoise;
    std::cout << "Enter " << XML_FILE << " to read numbers from xml file" << std::endl;
    //and so on...

    std::cin >> nChoise;
    switch(nChoise)
    {
    case XML_FILE:
    {
        DataReaderFromXML* pReader = new DataReaderFromXML();
        // gets file name from user...
        pReader->setFileName("/home/ai/PrimeNumbers/intervals.xml");
        ErrCodeRead er = prNumb.readData(pReader); //client hasn't setReader function
        //it gives reader object as a parameter of
        //ErrCodeRead readData(BaseDataReader* pReader); function
        if(READ_OK == er)
        {
            prNumb.parseData();
            DataSaverToXML saver;
            saver.setFileName("result.xml");
            ErrCodeWrite er = prNumb.saveData(&saver);
            switch(er)
            {
            case WRITE_FAILED:
                std::cout << "file wasn't saved" << std::endl;
                break;
            case WRITE_OK:
                std::cout << "file was saved successfuly" << std::endl;
                break;
            case NO_DATA_TO_SAVE:
                std::cout << "no data to save in file" << std::endl;
                break;
            }
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
            case BAD_ALLOC_READ:
                std::cout << "error: bad alloc" << std::endl;
                break;
            default:
                std::cout << "error: undefined error" << std::endl;
                break;
            }
        }
    }
        break;

    //todo: implement for file with other format or other source of data
    }



   return 0;
}
