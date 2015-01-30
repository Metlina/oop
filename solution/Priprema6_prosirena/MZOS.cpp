#include "MZOS.h"
#include <iostream>
#include <algorithm>
#include <functional>

template<typename RandomAccessIterator,typename Order>
void quicksort(RandomAccessIterator first, RandomAccessIterator last, Order order)
{
	if (last - first > 1)
	{
		RandomAccessIterator split = std::partition(first + 1, last, std::bind2nd(order, *first));
		std::iter_swap(first, split - 1);
		quicksort(first, split - 1, order);
		quicksort(split, last, order);
	}
}

template<typename RandomAccessIterator>
void quicksort(RandomAccessIterator first, RandomAccessIterator last)
{
	quicksort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

MZOS::MZOS()
{
	//for (int i = 0; i < this->studenti.size(); i++)
	//studenti[i] = new MZOS;
}

void MZOS::dodajStudenta(Student& stud)
{
	this->studenti.push_back(stud);
}


void MZOS::sortirajStudente()
{
	quicksort(studenti.begin(),studenti.end());
	//sort(studenti.begin(), studenti.end());
}

//void MZOS::ispisStudenta(int rb)
//{
//	for (int i = 0; i < rb; i++)
//	{
//		cout.precision(2);
//		cout.setf(ios::fixed, ios::floatfield);
//		cout << studenti[i];
//	}
//}

Student* MZOS::search(string& prez)
{
	int prvi = 0, drugi = studenti.size() - 1, srednji;

	while (prvi <= drugi)
	{
		srednji = (prvi + drugi) / 2;

		if (studenti[srednji] < prez)
		{
			prvi = srednji + 1;
		}
		else if (studenti[srednji] > prez)
		{
			drugi = srednji - 1;
		}
		else
			return &studenti[srednji];
	}
	/*int prvi = 0, drugi = studenti.size() - 1, srednji1, srednji2;

	while (prvi <= drugi)
	{
		srednji1 =  prvi + (drugi - prvi) / 3;
		srednji2 = prvi + 2 * (drugi - prvi) / 3;


		if (studenti[srednji1] < prez)
		{
			prvi = srednji1 + 1;
		}
		else if (studenti[srednji1] > prez)
		{
			prvi = srednji1 - 1;
		}
		else if (studenti[srednji2] > prez)
		{
			drugi = srednji2 - 1;
		}
		else if (studenti[srednji2] > prez)
		{
			drugi = srednji2 - 1;
		}
		else if (studenti[srednji1] == prez)
			return &studenti[srednji1];
		else
			return &studenti[srednji2];
	}*/
	return 0;
}