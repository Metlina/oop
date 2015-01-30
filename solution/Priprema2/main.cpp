#include <iostream>
#include "Pacijent.h"
#include "SistematskiPregled.h"

using namespace std;

int main()
{
	//inicijalizacija varijabli
	string imeDoktor, prezimeDoktor;
	string datum;
	string vrijeme;
	Pacijent pacijent;
	//vector<Pacijent> poljePacijent;
	string pretraga;
	int i, j, brojPacijenata, brojPretraga;
	char slovo;
	string ime, prezime, OIB, datumrodjenja;

	//temporalni objekt
	Pacijent *tempPacijent = new Pacijent;
	SistematskiPregled *tempPregled = new SistematskiPregled;

	//upisivanje u konzolu
	cout << "Upisite ime i prezime doktora!" << endl;
	cin >> imeDoktor >> prezimeDoktor;
	//cout << "Upisiste prezime doktora!" << endl;
	//cin >> prezimeDoktor;
	SistematskiPregled pregled(imeDoktor, prezimeDoktor);
	cout << "Upisite datum i vrijeme!" << endl;
	cin >> datum >> vrijeme;
	cout << "Upisite broj pretraga" << endl;
	cin >> brojPretraga;
	cout << "Upisite pretrage!" << endl;
	for (i = 0; i < brojPretraga; i++)
	{
		cin >> pretraga;
		pregled.dodajPretragu(pretraga);
	}
	cout << "Upisite broj pacijenata!" << endl;
	cin >> brojPacijenata;
	cout << "Upisite pacijente : ime, prezime, oib, datum rodjena!" << endl;
	for (j = 0; j < brojPacijenata; j++)
	{
		cin >> pacijent.ime >> pacijent.prezime >> pacijent.OIB >> pacijent.datumRodjenja;
		pregled.dodajPacijenta(pacijent); 
	}

	cout << "Upisite prvo slovo imena pacijenta!" << endl;
	cin >> slovo;
	cout << "\n" << endl;

	SistematskiPregled *doktor = new SistematskiPregled(imeDoktor, prezimeDoktor);

	//pozivanje metoda iz SistematskiPregled.h
	//SistematskiPregled pregled(imeDoktor, prezimeDoktor);
	//pregled.dodajPretragu(pretraga);
	//pregled.dodajPacijenta(pacijent);
	pregled.postaviVrijemePregleda(datum, vrijeme);
	pregled.ispisiOsnovnePodatke();
	pregled.ispisiPretrage();
	pregled.ispisiPacijentePrvoSlovo(slovo);

	pregled.~SistematskiPregled();

	system("PAUSE");

	return 0;
}