#pragma once
#include "Biljka.h"
class Stablo :
	public Biljka
{
private:
	bool plodovi;
	int grane;
public:

	Stablo(string ime, int visina, double cijena, bool plodovi, int grane) : Biljka(ime, visina, cijena)
	{
		this->plodovi = plodovi;
		this->grane = grane;
	}

	void uberi()
	{
		if (plodovi)
			cout << ime << ": ubrani plodovi" << endl;
		else
			cout << ime << " nema plodova" << endl;
	}

	void mirisi()
	{
		cout << "Stablo ne mirisi" << endl;
	}

	void narasti(int broj)
	{
		grane += broj;
	}
};

