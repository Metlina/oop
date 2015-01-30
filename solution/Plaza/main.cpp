#include<iostream>
#include"Plaza.h"
#include"Predmeti.h"

using namespace std;

int main()
{
	int brojPlaza, i, j;
	int velicinaPlaze;
	double gpsX, gpsY;
	int brojPredmeta;
	string opisPredmeta;
	int kolicina;

	Plaza *plaza = new Plaza;
	Predmeti *predmet = new Predmeti;

	cout << "Unesite broj plaza (N):" << endl;
	cin >> brojPlaza;
	for (i = 0; i < brojPlaza; i++)
	{
		cout << "Unesite velicinu i lokaciju za " << i+1 << ". plazu" << endl;
		cin >> velicinaPlaze;
		cin >> gpsX >> gpsY;
	}
	cout << "Unesite redni broj predmeta (M): " << endl;
	cin >> brojPredmeta;
	for (j = 0; j < brojPredmeta; j++)
	{
		cout << "Unesite redni broj plaze kojoj pripada " << j+1 << ". predmet: " << endl;
	}
	cout << "Unesite kolicinu i opis predmeta: " << endl;
	cin >> kolicina >> opisPredmeta;
	cout << "Ispis plaza i predmeta:" << endl;

	system("PAUSE");

	return 0;
}