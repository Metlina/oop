#include "MontaznaKuca.h"

MontaznaKuca::MontaznaKuca(void)
{
}
MontaznaKuca::MontaznaKuca(double kvadratura, string bojaFasade, string imaVrt)
{
	this->kvadratura = kvadratura;
	this->bojaFasade = bojaFasade;
	if (imaVrt == "DA")
		postojiVrt == true;
	else
		postojiVrt == false;
}
MontaznaKuca::MontaznaKuca(const MontaznaKuca& kuca)
{
	this->kvadratura = kuca.kvadratura;
	this->bojaFasade = kuca.bojaFasade;
	this->vlasnik = kuca.vlasnik;
	this->postojiVrt = kuca.postojiVrt;
	this->kuhinja = new Kuhinja(*kuca.kuhinja);
	for (int i = 0; i < kuca.sobe.size(); i++)
		this->sobe.push_back(new Soba(*kuca.sobe[i]));
}
MontaznaKuca::~MontaznaKuca(void)
{
	if (getVlasnik() != "Template kuca")
		cout << getVlasnik() << " - narudzba zaprimljena!" << endl;
}

MontaznaKuca& MontaznaKuca::operator=(const MontaznaKuca& kuca)
{
	this->kvadratura = kuca.kvadratura;
	this->bojaFasade = kuca.bojaFasade;
	this->vlasnik = kuca.vlasnik;
	this->postojiVrt = kuca.postojiVrt;
	this->kuhinja = new Kuhinja(*kuca.kuhinja);
	//this->sobe = kuca.sobe;
	for (int i = 0; i < kuca.sobe.size(); i++)
		this->sobe.push_back(new Soba(*kuca.sobe[i]));
	return *this;
}

void MontaznaKuca::setKuhinja(Kuhinja* kuhinja)
{
	this->kuhinja = kuhinja;
}
void MontaznaKuca::dodajSobu(Soba* soba)
{
	sobe.push_back(soba);
}
void MontaznaKuca::setBojaFasade(string novaBoja)
{
	bojaFasade = novaBoja;
}
void MontaznaKuca::setVlasnik(string imePrezime)
{
	vlasnik = imePrezime;
}

Soba* MontaznaKuca::nadjiSobu(string naziv)
{
	int i; 
	for (i = 0; i < sobe.size(); i++){
		if (sobe[i]->getNaziv() == naziv)
			return sobe[i];
	}
	return NULL;
}

Kuhinja* MontaznaKuca::getKuhinja(){ return kuhinja; }
double MontaznaKuca::getKvadratura(){ return kvadratura; }
string MontaznaKuca::getbojaFasade(){ return bojaFasade; }

bool MontaznaKuca::imaVrt()
{
	if (postojiVrt = "DA")
		return true;
	else
		return false;
}

string MontaznaKuca::getVlasnik(){ return this->vlasnik; }

void MontaznaKuca::ispisiKucu()
{
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	cout << getVlasnik() << ": " << getbojaFasade() << " kuca, " << getKvadratura() << "m2" << endl;;
	getKuhinja()->ispisiKuhinju();
	for (int i = 0; i < sobe.size()-1; i++)
	{
		sobe[i]->ispisiSobu();
		cout << ", ";
	}
	for (int i = (sobe.size()-1); i < sobe.size(); i++)
	{
		sobe[i]->ispisiSobu();
	}
	cout << endl;
}