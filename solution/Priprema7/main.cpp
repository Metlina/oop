#include <iostream>
#include "Posta.h"
using namespace std;

int main()
{
	double osnovica, bonus, koefPlace, vrijed;
	string ime, prez, oib, kvart;
	int nPo, nPr, nPa, nPn;

	cin >> osnovica >> bonus;
	Posta p(osnovica, bonus);

	cin >> nPo;
	while (nPo--)
	{
		cin >> ime >> prez >> oib >> koefPlace >> kvart;
		Postar* tmpPos = new Postar(ime, prez, oib, koefPlace, kvart);
		if (!p.dodajPostara(tmpPos))
			cout << "Kvart " << kvart << " vec ima postara!" << endl;
	}

	cin >> nPr;
	while (nPr--)
	{
		cin >> ime >> prez >> oib >> kvart;
		Primatelj* tmpPri = new Primatelj(ime, prez, oib);
		if (!p.dodajPrimatelja(tmpPri, kvart))
			cout << "Nema postara za kvart " << kvart << "!" << endl;
	}

	cin >> nPa;
	while (nPa--)
	{
		cin >> ime >> prez >> kvart >> vrijed;
		Paket* tmpPak = new Paket();
		tmpPak->primatelj = prez + " " + ime;
		tmpPak->kvart = kvart;
		tmpPak->vrijednost = vrijed;
		p.zaprimiPosiljku(tmpPak);
	}

	p.dispatch();

	cin >> nPn;
	vector<string> najPost = p.getNajboljiPostari(nPn);
	cout << "Ispis " << najPost.size() << " najboljih postara:" << endl;
	for (int i = 0; i<najPost.size(); i++)
		cout << najPost[i] << endl;

	cout << "Ispis liste isporuka:" << endl;
	vector<string> sviPrim = p.getListaIsporuka();
	for (int i = 0; i<sviPrim.size(); i++)
		cout << sviPrim[i] << endl;

	vector<string> nedostavljeno = p.getListaNedostavljenih();
	if (nedostavljeno.size() > 0)
	{
		cout << "Nedostavljene posiljke na ime:" << endl;
		for (int i = 0; i<nedostavljeno.size(); i++)
			cout << nedostavljeno[i] << endl;
	}
}