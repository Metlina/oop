#pragma once
#include <string>
using namespace std;

class Biljka
{
protected:
	string ime;
	int visina;
	double cijena;
public:
	//konstruktor Biljka
	Biljka(string ime, int visina, double cijena) : ime(ime), visina(visina), cijena(cijena) { }

	string getIme()
	{
		return ime;
	}

	int getVisina()
	{
		return visina;
	}

	double getCijena()
	{
		return cijena;
	}

	//virtualne funkcije sa =0 znaci da se svaka funkcija mora napisati u podklasi, tj u podklasi Cvijet i Stablo 
	virtual void uberi() = 0;
	virtual void mirisi() = 0;

	//virtualne funkcije bez =0 znaci da ce se za svaku podklasu pozivati ova funkcija, osim ako u toj podklasi nije napisana funkcija istog imena i parametara
	virtual void narasti(int broj)
	{
		visina += broj;
	}
};