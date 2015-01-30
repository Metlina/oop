#include "Osoba.h"

Osoba::Osoba(string ime, string prezime, string oib)
{
	this->ime = ime;
	this->prezime = prezime;
	this->oib = oib;
}
string Osoba::getIme(){ return this->ime; }
string Osoba::getPrezime(){ return this->prezime; }
string Osoba::getOIB(){ return this->oib; }