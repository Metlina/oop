#include "Crtanka.h"

Crtanka::Crtanka()
{
}
Crtanka::~Crtanka()
{
}

void Crtanka::dodajLik(GeomLik* lik)
{
	likovi.push_back(lik);
}
GeomLik* Crtanka::getLik(int id)
{
	return likovi.at(id);
}

void Crtanka::ispisiSveLikove()
{
	for (int i = 0; i < likovi.size(); i++)
	{
		likovi[i]->ispisi();
	}
}
double Crtanka::getUkupanOpseg()
{
	double ukupnoO = 0;
	for (int i = 0; i < likovi.size(); i++)
	{
		ukupnoO += likovi[i]->getOpseg();
	}
	return ukupnoO;
}

double Crtanka::getUkupnuPovrsinu()
{
	double ukupnoP = 0;
	for (int i = 0; i < likovi.size(); i++)
	{
		ukupnoP += likovi[i]->getPovrsina();
	}
	return ukupnoP;
}