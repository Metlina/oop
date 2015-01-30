#pragma once
#include <string>
using namespace std;

class Pacijent
{
public:
	// atributi klase
	string ime;
	string prezime;
	string OIB;
	string datumRodjenja;

	// konstruktor
	Pacijent(void) {}
	Pacijent(string ime, string prezime, string OIB, string datRodj) : ime(ime), prezime(prezime), OIB(OIB), datumRodjenja(datRodj) { }
};