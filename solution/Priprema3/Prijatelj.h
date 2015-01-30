#include <string>
#include <vector>
#include "Pice.h"
using namespace std;

class Prijatelj
{
private:
	string ime;
	vector<Pice*> omiljenaPica;
public:

	Prijatelj(void) { }
	Prijatelj(string ime) : ime(ime) { }

	void dodajPice(Pice* picePtr)
	{
		this->omiljenaPica.push_back(picePtr);
	}

	vector<Pice*> getPopisPica()
	{
		return this->omiljenaPica;
	}

	string getIme()
	{
		return this->ime;
	}
};