#include <iostream>
#include "Cvjecarnica.h"
using namespace std;
using namespace CvjecarnicaExceptions;

int main()
{
	Cvjecarnica shop("Zelena dolina");

	//upisujemo broj biljaka
	int n;
	cin >> n;

	string ime, boja;
	int visina, brojGrana;
	string plodovi;
	double cijena;

	//dodajemo biljke
	while (n--)
	{
		char c;
		cin >> c;
		if (c == 'C')
		{
			cin >> ime >> visina >> cijena >> boja;
			//u funkciji dodaj biljku, ako je iznad 10000 cm baca exception: TooHighException
			try
			{
				shop.dodajBiljku(new Cvijet(ime, visina, cijena, boja));
			}
			//ako je biljka iznad 10000 cm uhvatit ce exception i ispisat:
			catch (TooHighException ex)
			{
				cout << "Biljka ne moze biti toliko visoka!" << endl;
			}

		}
		else if (c == 'S')
		{
			cin >> ime >> visina >> cijena >> plodovi >> brojGrana;
			//u funkciji dodaj biljku, ako je iznad 10000 cm baca exception: TooHighException
			try
			{
				shop.dodajBiljku(new Stablo(ime, visina, cijena, plodovi == "DA" ? true : false, brojGrana));
			}
			//ako je biljka iznad 10000 cm uhvatit ce exception i ispisat:
			catch (TooHighException ex)
			{
				cout << "Biljka ne moze biti toliko visoka!" << endl;
			}

		}
	}

	//upisujemo broj litara vode
	int brLitaraVode;
	cin >> brLitaraVode;

	//pozivamo funkciju zalijevanje
	shop.zalijevanje(brLitaraVode);

	//upisujemo koliko cemo biljaka pomirisat
	int m;
	cin >> m;
	while (m--)
	{
		//za svaku biljku upisujemo id, da znamo koju cemo pomirisat
		int id;
		cin >> id;
		shop.pomirisiBiljku(id);
	}

	//sortiramo sve biljke
	shop.posloziBiljke();

	//ispisujemo sve biljke i cijene
	shop.otvoriCvjecarnu();

	//za svaku biljku pozivamo funkciju branje
	shop.branje();

	system("pause");

	return 0;
}