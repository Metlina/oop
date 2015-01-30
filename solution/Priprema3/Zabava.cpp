#include "Zabava.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool sortiranje(Pice* first,  Pice* second) { return (first->kolikoLjudiZeli()) > (second->kolikoLjudiZeli()); }

Zabava::Zabava(double budzet)
{
	this->budzet = budzet;
}

Zabava::~Zabava()
{
}

void Zabava::dodajPrijatelja(Prijatelj* prijatelj)
{
	uzvanici.push_back(prijatelj);
}

void Zabava::dodajPice(Pice* pice)
{
	popisPica.push_back(pice);
}

double Zabava::getBudzet()
{
	return budzet;
}

Prijatelj* Zabava::getPrijatelj(int id)
{
	return uzvanici.at(id);
}

Pice* Zabava::nadjiPice(int PiceId)
{
	//popisPica.at(PiceId)->kolikoLjudiZeli();
	return popisPica[PiceId];
}

void Zabava::ispisiPopisZaKupnju()
{
	double tempBudet = getBudzet(), ukupniBudet = 0;
	int br, brojac;
	double k;
	sort(popisPica.begin(), popisPica.end(), sortiranje);
	cout << "Popis za kupnju:" << endl;
	for (br = 0; br < popisPica.size(); br++)
	{
		k = (double)popisPica[br]->kolikoLjudiZeli() / popisPica[br]->getBrojOsoba();
		k = (int)(k + 0.5);
		if (k > 0 && k*popisPica[br]->getCijena() <= tempBudet)
		{
			cout << popisPica[br]->getIme() << " x" << k << " = " << k*popisPica[br]->getCijena() << "kn" << endl;
			tempBudet = tempBudet - (k*popisPica[br]->getCijena());
			ukupniBudet = ukupniBudet + (k*popisPica[br]->getCijena());
		}
		else
		{
			brojac = k - 1;
			while (brojac > 0)
			{
				if (brojac*popisPica[br]->getCijena() <= tempBudet)
				{
					cout << popisPica[br]->getIme() << " x" << brojac << " = " << brojac*popisPica[br]->getCijena() << "kn" << endl;
					tempBudet = tempBudet - (brojac*popisPica[br]->getCijena());
					ukupniBudet = ukupniBudet + (brojac*popisPica[br]->getCijena());
				}
				brojac--;
			}
		}
	}
	cout << "Ukupni trosak: " << ukupniBudet << "kn"<< endl;
}