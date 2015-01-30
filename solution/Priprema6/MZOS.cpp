#include "MZOS.h"
#include <iostream>
#include <algorithm>

MZOS::MZOS()
{
	//for (int i = 0; i < this->studenti.size(); i++)
		//studenti[i] = new MZOS;
}

void MZOS::dodajStudenta(Student stud)
{
	this->studenti.push_back(stud);
}

void MZOS::sortirajStudente()
{
	/*int n = 0;
	do
	{
		n = 0;
		for (int i = 0; i < studenti.size()-1; i++)
		{
			if ((studenti[i] < studenti[i+1]) == true)
			{
				Student student = studenti[i];
				studenti[i] = studenti[i + 1];
				studenti[i + 1] = student;
				n = 1;
			}
		}
	} while (n = 1);*/

	int n = 1;
	while (n==1)
	{
		n = 0;
		for (int i = 0; i < studenti.size() - 1; i++)
		{
			if ((studenti[i] < studenti[i + 1]))
			{
				Student student = studenti[i];
				studenti[i] = studenti[i + 1];
				studenti[i + 1] = student;
				n = 1;
			}
		}
	}
}

void MZOS::ispisStudenta(int rb)
{
	for (int i = 0; i < rb; i++)
	{
		cout.precision(2);
		cout.setf(ios::fixed, ios::floatfield);
		cout << studenti[i];
	}
}

Student* MZOS::search(string& prez)
{
	for (int i = 0; i < studenti.size(); i++)
	{
		if (studenti[i].getPrezime() == prez)
			return &studenti[i];
	}
	return NULL;
}