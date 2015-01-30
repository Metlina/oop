#include "Soba.h"
Soba::Soba(void)
{
}
Soba::Soba(string nazivSobe, string prozor)
{
	naziv = nazivSobe;
	if (prozor == "DA")
		imaProzor = true;
	else
		imaProzor = false;
}
Soba::Soba(const Soba& soba)
{
	naziv = soba.naziv;
	imaProzor = soba.imaProzor;
}
Soba::~Soba(void)
{
}

void Soba::setProzor(string prozor)
{
	if (prozor == "DA")
		imaProzor = true;
	else
		imaProzor = false;
}
string Soba::getNaziv(){ return naziv; }
void Soba::ispisiSobu()
{
	if (this->imaProzor == true)
		cout << naziv << " s prozorom" ;
	else
		cout << naziv ;
}
