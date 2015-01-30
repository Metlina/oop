#include "Utakmica.h"


Utakmica::Utakmica(string prvo, string drugo){
	this->domacaEkipa = prvo;
	this->gostujucaEkipa = drugo;
	this->brojGolovaDomaca = 0;
	this->brojGolovaGostujuca = 0;
}

Utakmica::~Utakmica(){}

string Utakmica::getDomacaEkipa() const{ return this->domacaEkipa; }
string Utakmica::getGostujucaEkipa() const{ return this->gostujucaEkipa; }
int Utakmica::getBrojGolovaDomaca() const{ return this->brojGolovaDomaca; }
int Utakmica::getBrojGolovaGostujuca() const{ return this->brojGolovaGostujuca; }

//void Utakmica::setDomacaEkipa(string domacaEkipa)
//{
//	this->domacaEkipa = domacaEkipa;
//}
//void Utakmica::setGostujucaEkipa(string gostujucaEkipa)
//{
//	this->gostujucaEkipa = gostujucaEkipa;
//}
//void Utakmica::setBrojGolovaDomaca(int brojGolovaDomaca)
//{
//	this->brojGolovaDomaca = brojGolovaDomaca;
//}
//void Utakmica::setBrojGolovaGostujuca(int brojGolovaGostujuca)
//{
//	this->brojGolovaGostujuca = brojGolovaGostujuca;
//}
void Utakmica::dodajGol(const string imeEkipe)
{
	if (this->domacaEkipa == imeEkipe)
		this->brojGolovaDomaca++;
	else
		this->brojGolovaGostujuca++;
}