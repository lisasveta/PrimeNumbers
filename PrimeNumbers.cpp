// PrimeNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PrimeNumbersFromFile.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main()
{
	{
		PrimeNumbersFromFile prNumbers;
		ErrCode errCode = prNumbers.getDataFromFile("intervals.xml");
		//prNumbers.showNumbers();
		//if(prNumbers.size() > 0)
		if (errCode == ErrCode::READ_OK)
		{
			errCode = prNumbers.saveToFile("results.xml");
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
	}
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory Ok!" << endl;
	
    return 0;
}

