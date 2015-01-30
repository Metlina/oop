#pragma once
#include<iostream>
#include<cstdlib>
//#include <algorithm>
//#include <functional>

using namespace std;

template<class T>

class SuperList
{
private:
	T* niz, *nizTemp;
	int cnt;
	int capacity;
public:
	SuperList()	
	{
		capacity = 5;
		cnt = 0;
		niz = new T[capacity];
		//niz = (T*)malloc(sizeof(T)*capacity);
	}

	//dodaje novi element u listu
	void add(T item)
	{
		if (cnt >= capacity)
		{
			capacity *= 2;
			//nizTemp = (T*)realloc(niz, sizeof(T)*capacity);
			nizTemp = new T[capacity];

			for (int i = 0; i < cnt; i++)
			{
				
				nizTemp[i] = niz[i];
			}
			//niz = (T*)malloc(sizeof(T)*capacity);
			niz = new T[capacity];

			for (int j = 0; j < cnt; j++)
			{
				niz[j] = nizTemp[j];
			}
		}
		niz[cnt++] = item;
		zamijeni();
	}

	//briše sve elemente identične elementu item
	void remove(T item)
	{
		int deleted = 0, newNiz = 0;
		for (int i = 0; i < cnt; i++)
		{
			if (niz[i] == item)
				deleted++;
			else
				niz[newNiz++] = niz[i];
		}
		cnt -= deleted;
	}

	//brišesve elemente iz liste
	void clear()
	{
		delete[] niz;
		cnt = 0;
		capacity = 5;
		niz = new T[capacity];
	}

	//vraća broj elemenata u listi
	int count()
	{
		return cnt;
	}

	//vraća element na traženoj poziciji(npr lista[3] vraća 4. element)
	T& operator[](int pozicija)
	{
		return niz[pozicija];
	}

	//vraća pointer na traženi element; ako element ne postoji, vraća NULL
	T* find(T item)
	{
		for (int i = 0; i < cnt; i++)
		{
			if (item == niz[i])
				return &niz[i];
		}
		return NULL;
	}

	//ispisuje sve elemente u listi
	void print()
	{
		cout << "Ispis liste: ";
		for (int i = 0; i < cnt - 1; i++)
			cout << niz[i] << ", ";
	}

	//ispisuje "count" elementa počevši od indeksa start
	void print(int start, int count)
	{
		cout << "Ispis liste: ";
		for (int i = start; i < count - 1; i++)
			cout << niz[i] << ", ";
		for (int j = count - 1; j < count; j++)
			cout << niz[j];
	}

	//dodaje sve elemente druge liste(other) u prvu
	SuperList<T>& operator+=(SuperList<T>& other)
	{
		//niz = (T*)realloc(niz, sizeof(T) * 3);
		for (int i = 0; i < other.cnt; i++)
		{
			add(other[i]);
		}
		return *this;
	}

	void zamijeni()
	{
		for (int i = 0; i < cnt; i++)
		{
			for (int j = i + 1; j < cnt; j++)
			{
				if (niz[i] > niz[j])
				{
					T nizTemp = niz[i];
					niz[i] = niz[j];
					niz[j] = nizTemp;
				}
			}
		}
	}

	//nije mi jasno zasto ovo ne radi
	/*template<typename RandomAccessIterator, typename Order>
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
	}*/
};