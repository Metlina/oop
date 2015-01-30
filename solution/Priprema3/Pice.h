#include <string>
using namespace std;

class Pice
{
private:
	string ime;
	int zaKolikoOsoba;
	double cijena;
	int kolikoUzvanikaZeli;
public:
	Pice(void)
	{
		kolikoUzvanikaZeli = 0;
	}

	Pice(string ime, double cijena) : ime(ime), cijena(cijena)
	{
		kolikoUzvanikaZeli = 0;
	}

	void setBrojOsoba(int zaKolikoOsoba)
	{
		this->zaKolikoOsoba = zaKolikoOsoba;
	}

	int getBrojOsoba()
	{
		return this->zaKolikoOsoba;
	}

	double getCijena()
	{
		return this->cijena;
	}

	string getIme()
	{
		return this->ime;
	}

	void povecajBrojac()
	{
		this->kolikoUzvanikaZeli++;
	}

	int kolikoLjudiZeli()
	{
		return this->kolikoUzvanikaZeli;
	}
};