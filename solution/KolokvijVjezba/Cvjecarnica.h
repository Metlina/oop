#pragma once
#include <vector>
#include "Cvijet.h"
#include "Stablo.h"
#include "TooHighException.h"
using namespace std;

class Cvjecarnica
{
private:
	string ime;
	vector<Biljka*> biljke;
public:
	Cvjecarnica(string ime);
	~Cvjecarnica();

	void dodajBiljku(Biljka* biljka);
	void zalijevanje(int litaraVode);
	void branje();
	void pomirisiBiljku(int id);
	void posloziBiljke();
	void otvoriCvjecarnu();
};