// PrimeNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PrimeNumbers.h"
#include "DataReaderFromFile.h"
#include "DataSaverToFile.h"


int main()
{
	{
		PrimeNumbers prNumbers;
		DataReader *pDataReader = nullptr;
		DataSaver *pDataSaver = nullptr;
		ErrCode errCode;

		//reading data from file
		try
		{
			pDataReader = new DataReaderFromFile("intervals.xml");
		}
		catch (const std::bad_alloc & e)
		{
			std::cout << "Allocation failed: " << e.what() << '\n';
			std::cout << "May you close some program and try call this again?\n";
		}
		if (nullptr != pDataReader)
		{
			errCode = prNumbers.readData(pDataReader);
			prNumbers.parseData();

			if (errCode == ErrCode::READ_OK)
			{
				prNumbers.showNumbers();
			}
			else
				switch (errCode)
				{
				case READ_FILED:
					cout << "error: READ_FILED" << endl;
					break;
				case FILE_NOT_EXIST:
					cout << "error: FILE_NOT_EXIST" << endl;
					break;
				case FILE_IS_EMPTY:
					cout << "error: FILE_IS_EMPTY" << endl;
					break;
				case FILE_NO_ACCESS:
					cout << "error: FILE_NO_ACCESS" << endl;
					break;
				}
			delete pDataReader;
		}
		//save data to file
		if (!prNumbers.empty())
		{
			try
			{
				pDataSaver = new DataSaverToFile("results.xml");
			}
			catch (const std::bad_alloc & e)
			{
				std::cout << "Allocation failed: " << e.what() << '\n';
				std::cout << "May you close some program and try call this again?\n";
			}
			if (nullptr != pDataSaver)
			{
				errCode = prNumbers.saveData(pDataSaver);
				if (errCode == ErrCode::WRITE_OK)
					cout << "File saved successfilly!" << endl;
				else
					switch (errCode)
					{
					case WRITE_FAILED:
						cout << "error: WRITE_FAILED" << endl;
						break;
					case FILE_NO_ACCESS:
						cout << "error: FILE_NO_ACCESS" << endl;
						break;
					}
				delete pDataSaver;
			}
		}
	}
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory Ok!" << endl;
	
    return 0;
}

