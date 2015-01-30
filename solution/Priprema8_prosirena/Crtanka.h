#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Tocka.h"
using namespace std;

class Crtanka
{
private:
	char** matrica;
	char zadaniKist;
	char pozadina;
	int brRed, brStup;
public:
	Crtanka(int rows, int cols, char kist, char pozadina);
	~Crtanka();

	void ispisi();
	void ocisti();
	void noviKist(char noviKist);
	bool jeUnutarOkvira(Tocka p);
	char getBoja(Tocka p);

	void tocka(Tocka p);
	void crta(Tocka p1, Tocka p2);
	void trokut(Tocka p1, Tocka p2, Tocka p3);
	void pravokutnik(Tocka p1, Tocka p2);
	void kruznica(Tocka p, int radius);
	void poligon(vector<Tocka> kutovi);
	void oboji(Tocka p, char novaBoja);
	void napisi(Tocka p, string text);
};