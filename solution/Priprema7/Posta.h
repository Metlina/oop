#pragma once
#include "Paket.h"
#include "Postar.h"
#include "Primatelj.h"
#include <vector>

using namespace std;

class Posta : Paket
{
private:
	double osnovica;
	double bonus;
public:
	//Posta();
	Posta(double osnovica, double bonus);
	//~Posta();

	bool dodajPostara(Postar* postar);
	bool dodajPrimatelja(Primatelj* primatelj, string kvart);

	void zaprimiPosiljku(Paket* paket);

	void dispatch();

	vector<string> getNajboljiPostari(int n);
	vector<string> getListaIsporuka();
	vector<string> getListaNedostavljenih();
};

