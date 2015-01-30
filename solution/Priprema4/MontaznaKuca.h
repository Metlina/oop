#include <vector>
#include "Kuhinja.h"
#include "Soba.h"
using namespace std;

class MontaznaKuca
{
private:
	double kvadratura;
	string bojaFasade;
	string vlasnik;
	bool postojiVrt;
	Kuhinja* kuhinja;
	vector<Soba*> sobe;
public:
	MontaznaKuca(void);
	MontaznaKuca(double kvadratura, string bojaFasade, string imaVrt);
	MontaznaKuca(const MontaznaKuca& kuca);
	~MontaznaKuca(void);

	MontaznaKuca& operator=(const MontaznaKuca& kuca);

	void setKuhinja(Kuhinja* kuhinja);
	void dodajSobu(Soba* soba);
	void setBojaFasade(string novaBoja);
	void setVlasnik(string imePrezime);

	Soba* nadjiSobu(string naziv);
	Kuhinja* getKuhinja();
	double getKvadratura();
	string getbojaFasade();
	bool imaVrt();
	string getVlasnik();

	void ispisiKucu();
};