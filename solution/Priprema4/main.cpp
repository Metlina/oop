#include "MontaznaKuca.h"
using namespace std;

int main()
{
	string tmpBoja, tmpVrt;
	double tmpKvad;
	cin >> tmpBoja >> tmpKvad >> tmpVrt;
	MontaznaKuca templateKuca(tmpKvad, tmpBoja, tmpVrt);
	templateKuca.setVlasnik("Template kuca");

	int brPlam;
	string tmpPer;
	cin >> tmpBoja >> brPlam >> tmpPer;
	templateKuca.setKuhinja(new Kuhinja(tmpBoja, brPlam, tmpPer));

	int nSoba;
	string tmpIme, tmpProz;
	cin >> nSoba;
	while (nSoba--)
	{
		cin >> tmpIme >> tmpProz;
		templateKuca.dodajSobu(new Soba(tmpIme, tmpProz));
	}

	int brojNarudzbi;
	cin >> brojNarudzbi;

	MontaznaKuca* narudzba = new MontaznaKuca[brojNarudzbi];
	string imeVlasnika, novaFasada, novaBojaK, novaPerilica, trazenaSoba, novaSoba, noviProzor;
	int noviPlamenici;
	int a, b, c;

	for (int i = 0; i<brojNarudzbi; i++)
	{
		narudzba[i] = templateKuca;
		cin >> imeVlasnika;
		narudzba[i].setVlasnik(imeVlasnika);

		cin >> a;
		if (a)
		{
			cin >> novaFasada;
			narudzba[i].setBojaFasade(novaFasada);
		}

		cin >> b;
		if (b)
		{
			cin >> novaBojaK >> noviPlamenici >> novaPerilica;
			Kuhinja* trenutnaKuhinja = narudzba[i].getKuhinja();
			trenutnaKuhinja->setBojaKuhinje(novaBojaK);
			trenutnaKuhinja->setBrojPlamenika(noviPlamenici);
			trenutnaKuhinja->setPerilica(novaPerilica);

		}

		cin >> c;
		while (c--)
		{
			cin >> trazenaSoba >> noviProzor;
			Soba* soba = narudzba[i].nadjiSobu(trazenaSoba);

			if (soba != NULL)
			{
				soba->setProzor(noviProzor);
			}

			else
			{
				soba = new Soba(trazenaSoba, noviProzor);
				narudzba[i].dodajSobu(soba);
			}
		}
	}
	// kraj unosa

	cout << "Popis narudzbi:" << endl;
	for (int i = 0; i<brojNarudzbi; i++)
	{
		cout << (i + 1) << ". ";
		narudzba[i].ispisiKucu();
		cout << endl;
	}

	delete[] narudzba;
	return 0;
}