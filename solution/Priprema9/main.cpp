#include"SuperList.h"
#include <string>

using namespace std;

int main()
{
	SuperList<string> a, b;

	int n1, n2;
	//Kreiranje prve liste
	cin >> n1;
	for (int i = 0; i < n1; ++i) {
		string tmp;
		cin >> tmp;
		a.add(tmp);
	}

	//Kreiranje druge liste
	cin >> n2;
	for (int i = 0; i < n2; ++i) {
		string tmp;
		cin >> tmp;
		b.add(tmp);
	}

	//Spoji liste
	a += b;

	//Ucitaj broj brisanja iz liste
	int brBrisanje;
	cin >> brBrisanje;
	for (int i = 0; i < brBrisanje; ++i) {
		string trazeni;
		cin >> trazeni;
		a.remove(trazeni);
	}

	//Ucitaj broj izmjena
	int br;
	cin >> br;
	for (int i = 0; i < br; ++i) {
		string *nadeni;
		string trazeni;
		cin >> trazeni;
		nadeni = a.find(trazeni);
		if (nadeni != NULL) {
			string dodatak;
			cin >> dodatak;
			*nadeni += dodatak;
		}

	}

	//Ispisi od pocetnog indeksa prvih 'brElem' elemenata
	int pocIndeks;
	int brElem;
	cin >> pocIndeks >> brElem;
	cout << "Ispis liste: ";
	a.print(pocIndeks, brElem);
	cout << endl;
	system("pause");
	return 0;
}