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
		prNumbers.getDataFromFile("intervals.xml");
		//prNumbers.showNumbers();
		prNumbers.saveToFile("results.xml");
	}
	if (_CrtDumpMemoryLeaks())
		cout << "Memory Leaks!" << endl;
	else
		cout << "Memory Ok!" << endl;
    return 0;
}

