#include <iostream>
#include "Skupina.h"
#include "Utakmica.h"

using namespace std;

int main()
{
	int brojEkipa = 0, brojGolova = 0, bodovi = 0;
	string imeEkipe;
	string imeEkipeDalaGol, imeEkipePrimilaGol;

	//defaultni objekti
	Skupina tempSkupina;

	//unesi broj ekipa
	cin >> brojEkipa;

	//unesi ekipe
	for (int i = 0; i < brojEkipa; i++)
	{
		cin >> imeEkipe;
		//svaku ekipu dodajemo u objekt klase skupina putem funkcije za dodavanje ekipe
		tempSkupina.dodajEkipu(imeEkipe);
	}

	//pozivamo funkciju za slaganje zdrijeba
	tempSkupina.napraviZdrijeb();

	//unesi broj golova
	cin >> brojGolova;
	
	//za svaki gol unosimo ime ekipe koja je dala gol i ime ekipe koja je primila gol
	//zatim nalazimo utakmicu s te svije ekipe iz objekta klase Skupina te dodajemo gol
	for (int i = 0; i < brojGolova; i++)
	{
		cin >> imeEkipeDalaGol >> imeEkipePrimilaGol;
		//stvorimo objekt
		Utakmica* tempUtakmica = tempSkupina.getUtakmicu(imeEkipeDalaGol, imeEkipePrimilaGol);
		tempUtakmica->dodajGol(imeEkipeDalaGol);
	}


	//kada su uneseni svi golovi ispisujemo ekipu u obliku <ime ekipe> <broj bodova>
	for (int i = 0; i < brojEkipa; i++)
	{
		//izracunaj bodove
		cout << tempSkupina.getEkipa(i) << " " << tempSkupina.izracunajBodove(tempSkupina.getEkipa(i)) << endl;
	}

	return 0;
}