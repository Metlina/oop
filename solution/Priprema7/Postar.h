#pragma once
#include "Osoba.h"

class Postar : Osoba
{
private:
	double koeficijentPlace;
	string kvart;
public:
	Postar(string ime, string prezime, string oib, double koeficijentPlace, string kvart);
};

