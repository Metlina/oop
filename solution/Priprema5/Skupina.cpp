#include "Skupina.h"


Skupina::Skupina(){}

Skupina::~Skupina(){}

string Skupina::getNizEkipa() const
{
	for (int i = 0; i < nizEkipa.size(); i++)
		return nizEkipa.at(i);
}
Utakmica Skupina::getNizUtakmica() const
{
	for (int i = 0; i < nizUtakmica.size(); i++)
		return nizUtakmica.at(i);
}

//void Skupina::setNizEkipa()
//{
//	this->nizEkipa = nizEkipa;
//}
//void Skupina::setNizUtakmica()
//{
//	this->nizUtakmica = nizUtakmica;
//}

void Skupina::dodajEkipu(string imeEkipe)
{
	this->nizEkipa.push_back(imeEkipe);
}

string Skupina::getEkipa(int i) const
{
	return this->nizEkipa[i];
}

Utakmica* Skupina::getUtakmicu(const string domaca, const string gostujuca)
{
	int i, j;
	for (i = 0; i < this->nizUtakmica.size(); i++)
	{
		if ((this->nizUtakmica[i].getDomacaEkipa() == domaca && this->nizUtakmica[i].getGostujucaEkipa() == gostujuca) || (this->nizUtakmica[i].getDomacaEkipa() == gostujuca && this->nizUtakmica[i].getGostujucaEkipa() == domaca))
			return &nizUtakmica[i];
	}
	return 0;
}

void Skupina::napraviZdrijeb() 
{
	for (int i = 0; i < this->nizEkipa.size(); i++)
	{
		for (int j =i + 1; j < this->nizEkipa.size(); j++)
		{
			Utakmica utakmica(nizEkipa[i], this->nizEkipa[j]);
			this->nizUtakmica.push_back(utakmica);

		}
	}
}
int Skupina::izracunajBodove (const string imeEkipe) const
{
	int bodovi = 0;
	for (int i = 0; i < this->nizUtakmica.size(); i++)
	{
		if (this->nizUtakmica[i].getDomacaEkipa() == imeEkipe)
		{
			if (this->nizUtakmica[i].getBrojGolovaDomaca() > this->nizUtakmica[i].getBrojGolovaGostujuca())
			{
				bodovi += 3;
			}
			else if (this->nizUtakmica[i].getBrojGolovaDomaca() == this->nizUtakmica[i].getBrojGolovaGostujuca())
			{
				bodovi += 1;
			}
		}
		else if (this->nizUtakmica[i].getGostujucaEkipa() == imeEkipe)
		{
			if (this->nizUtakmica[i].getBrojGolovaGostujuca() > this->nizUtakmica[i].getBrojGolovaDomaca())
			{
				bodovi += 3;
			}
			else if (this->nizUtakmica[i].getBrojGolovaGostujuca() == this->nizUtakmica[i].getBrojGolovaDomaca())
			{
				bodovi += 1;
			}
		}
		else bodovi = 0;
	}
	return bodovi;
}
