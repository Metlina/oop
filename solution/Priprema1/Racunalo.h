#pragma once
#include <iostream>
#include <string>

using namespace std;

class Racunalo
{
public:

	//�lanske varijable
	double cpuGHz;     //frekvencija procesora u gigahercima
	int hddGB;         //koli�inu memorije tvrdog diska u gigabajtima
	char brand[25];    //ime brenda ra�unala(max. 1 rije�)

	//konstruktor
	Racunalo()
	{
	};
	Racunalo(char *laptop, double cpu, int hdd)
	{
	};

	//destruktor
	~Racunalo()
	{
	};

	void setRacunalo(char *laptop, double cpu, int hdd)
	{
		strncpy(brand, laptop, 25);
		cpuGHz = cpu;
		hddGB = hdd;
	};

	//ispisivanje vrijednosti, redoslijed : ime, brzinu procesora, memorija tvrdog diska
	/*void ispisiRacunalo()
	{
		cout << brand << " " << cpuGHz << " " << hddGB << endl;
	};*/
};

