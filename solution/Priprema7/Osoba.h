#pragma once
#include <string>
using namespace std;

class Osoba
{
protected:
	string ime, prezime, oib;
public:
	Osoba(string ime, string prezime, string oib);
	string getIme();
	string getPrezime();
	string getOIB();
};