#include <iostream>
#include <vector>
#include "Zabava.h"

using namespace std;

int main()
{
	double budzet;
	cout << "Unesite budget" << endl;
	cin >> budzet;
	Zabava party(budzet);

	int brPica;
	cout << "Unesite broj pica:" << endl;
	cin >> brPica;
	for (int i = 0; i<brPica; i++)
	{
		string tmpI;
		double tmpC;
		int tmpBr;
		cout << "Unesite ime pica, cijenu pica i za koliko ljudi je to pice :" << endl;
		cin >> tmpI >> tmpC >> tmpBr;
		Pice* tmpP = new Pice(tmpI, tmpC);
		tmpP->setBrojOsoba(tmpBr);
		party.dodajPice(tmpP);
	}

	int brUzv;
	cout << "Unesite broj prijatelja koji dolaze: " << endl;
	cin >> brUzv;
	for (int i = 0; i<brUzv; i++)
	{
		string tmpIme;
		int op;
		cout << "Unesite ime prijatelja i koje piæe hoce od ponudenih: " << endl;
		cin >> tmpIme >> op;
		Prijatelj* p = new Prijatelj(tmpIme);
		Pice* trazenoPice = party.nadjiPice(op - 1);
		trazenoPice->povecajBrojac();
		p->dodajPice(trazenoPice);
		party.dodajPrijatelja(p);
	}

	party.ispisiPopisZaKupnju();

	system("PAUSE");

	return 0;
}