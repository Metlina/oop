// Vjezba1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Auto.h"


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Auto a1;
	strcpy(a1.boja, "Roza");
	strcpy(a1.marka, "Mercedes");
	a1.cijena = 100000;

	cout << "Auto a1 je " << a1.boja << " " << a1.marka << ", kosta " << a1.cijena << endl;

	Auto a2;
	strcpy(a2.boja, "Tirkizno zeleni");
	strcpy(a2.marka, "Fiat");
	a2.cijena = 10000;

	cout << "Auto a2 je " << a2.boja << " " << a2.marka << ", kosta " << a2.cijena << endl;

	system("PAUSE");

	return 0;
}

