#pragma once
#include <iostream>
#include "Biljka.h"
class Cvijet :
	public Biljka
{
private:
	string boja;
public:
	Cvijet(string ime, int visina, double cijena, string boja) : Biljka(ime, visina, cijena)
	{
		this->boja = boja;
	}

	void uberi()
	{
		cout << "Ubran cvijet "<< ime << "!" << endl;
	}

	void mirisi()
	{
		cout << "mmmm kako mirisno..." << endl;
	}
};

