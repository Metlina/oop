#include <iostream>
#include <algorithm>
#include <string.h>
#include "Racunalo.h"

using namespace std;

//Racunalo::Racunalo(char *lol, double cpu, int hdd)
//{
//	strncpy(brand, lol, 25);
//	cpuGHz = cpu;
//	hddGB = hdd;
//}

//funkcija za usporedbu svih komponenti
bool usporedi(Racunalo prvo, Racunalo drugo)
{
	if (prvo.cpuGHz != drugo.cpuGHz)
	{
		return prvo.cpuGHz > drugo.cpuGHz;
	}
	else if (prvo.hddGB != drugo.hddGB)
	{
		return prvo.hddGB > drugo.hddGB;
	}
	else
	{
		return strcmp(prvo.brand, drugo.brand) < 0;
	}
}

int main()
{
	//definiranje varijabli
	int n, k, i;
	double cpu;
	int hdd;
	char laptop[25];

	//upisivanje komponenti N i K
	cin >> n >> k;

	//polje racunala
	Racunalo *poljeRacunala = new Racunalo[n];
	Racunalo racunalo;

	//stvori objekte tipa Raèunalo
	for (i = 0; i < n; i++)
	{
		cin >> poljeRacunala[i].brand >> poljeRacunala[i].cpuGHz >> poljeRacunala[i].hddGB;
		//poljeRacunala[i].setRacunalo(laptop, cpu, hdd);
		//poljeRacunala[i] = Racunalo(laptop, cpu, hdd);
		//racunalo.setRacunalo(laptop, cpu, hdd);
	};

	//sortiranje
	sort(&poljeRacunala[0], &poljeRacunala[n], usporedi);

	//ispisi svako k-raèunalo
	for (i = k - 1; i < n; i+=k)
	{
		cout << poljeRacunala[i].brand << " " << poljeRacunala[i].cpuGHz << " " << poljeRacunala[i].hddGB << endl;
	};

	return 0;
}