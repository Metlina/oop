#include "Posta.h"

Posta::Posta(double osnovica, double bonus)
{
	this->osnovica = osnovica;
	this->bonus = bonus;
}


bool Posta::dodajPostara(Postar* postar)
{
}
bool Posta::dodajPrimatelja(Primatelj* primatelj, string kvart)
{
}

void Posta::zaprimiPosiljku(Paket* paket)
{
}

void Posta::dispatch()
{
}

vector<string> Posta::getNajboljiPostari(int n)
{
	
}
vector<string> Posta::getListaIsporuka()
{
}
vector<string> Posta::getListaNedostavljenih()
{
}