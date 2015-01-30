#pragma once
#include <vector>
#include "Pravokutnik.h"
#include "Kvadrat.h"
#include "GeomLik.h"
using namespace std;

class Crtanka
{
private:
	vector<GeomLik*> likovi;
public:
	Crtanka();
	~Crtanka();

	void dodajLik(GeomLik* lik);
	GeomLik* getLik(int id);

	void ispisiSveLikove();
	double getUkupanOpseg();
	double getUkupnuPovrsinu();
};