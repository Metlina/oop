#include "Cvjecarnica.h"
#include <iomanip>


Cvjecarnica::Cvjecarnica(string ime)
{
	this->ime = ime;
}
Cvjecarnica::~Cvjecarnica()
{
	for (int i = 0; i < biljke.size(); i++)
	{
		delete biljke[i];
	}
	cout << "Sve biljke unistene" << endl;
}

void Cvjecarnica::dodajBiljku(Biljka* biljka)
{
	if (biljka->getVisina() > 10000)
		throw CvjecarnicaExceptions::TooHighException();
	biljke.push_back(biljka);
}
void Cvjecarnica::zalijevanje(int litaraVode)
{
	for (int i = 0; i < biljke.size(); i++)
	{
		biljke[i]->narasti(litaraVode);
	}
}
void Cvjecarnica::branje()
{
	for (int i = 0; i < biljke.size(); i++)
	{
		biljke[i]->uberi();
	}
}
void Cvjecarnica::pomirisiBiljku(int id)
{
	biljke[id]->mirisi();
}
void Cvjecarnica::posloziBiljke()
{
	for (int i = 0; i < biljke.size(); i++)
	{
		for (int j = i + 1; j < biljke.size(); j++)
		{
			if (biljke[j]->getVisina() > biljke[i]->getVisina())
				swap(biljke[i], biljke[j]);
			if (biljke[j]->getVisina() == biljke[i]->getVisina())
			{
				if (biljke[j]->getCijena() > biljke[i]->getCijena())
					swap(biljke[i], biljke[j]);
			}
		}
	}
}
void Cvjecarnica::otvoriCvjecarnu()
{
	cout << "Otvorena cvjecarnica" << ime << endl;
	cout << "Ponuda:" << endl;

	for (int i = 0; i < biljke.size(); i++)
	{
		cout << biljke[i]->getIme() << " - " << setprecision(2) << fixed << biljke[i]->getCijena() << " kn" << endl;
	}
}