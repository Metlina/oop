#include "Kuhinja.h"


Kuhinja::Kuhinja(void)
{
}
Kuhinja::Kuhinja(string boja, int plamenici, string perilica)
{
	bojaKuhinje = boja;
	brojPlamenika = plamenici;
	if (perilica == "DA")
		imaPerilicu = true;
	else
		imaPerilicu = false;
}
Kuhinja::Kuhinja(const Kuhinja& kuhinja)
{
	bojaKuhinje = kuhinja.bojaKuhinje;
	brojPlamenika = kuhinja.brojPlamenika;
	imaPerilicu = kuhinja.imaPerilicu;
}
Kuhinja::~Kuhinja(void)
{
}	

void Kuhinja::setBrojPlamenika(int broj)
{
	brojPlamenika = broj;
}
void Kuhinja::setBojaKuhinje(string boja)
{
	bojaKuhinje = boja;
}
void Kuhinja::setPerilica(string perilica)
{
	if (perilica == "DA")
	{
		imaPerilicu = true;
	}
	else
		imaPerilicu = false;
}
void Kuhinja::ispisiKuhinju()
{
	if (this->imaPerilicu == true)
		cout << bojaKuhinje << " kuhinja " << "(" << brojPlamenika << " plamenika, perilica dostupna" << ")" << endl;
	else
		cout << bojaKuhinje << " kuhinja " << "(" << brojPlamenika << " plamenika" << ")" << endl;
}