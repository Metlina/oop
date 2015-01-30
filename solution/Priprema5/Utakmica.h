#pragma once
#include <string>

using namespace std;

class Utakmica
{
private:
	string domacaEkipa;
	string gostujucaEkipa;
	int brojGolovaDomaca;
	int brojGolovaGostujuca;
public:
	Utakmica(string prvo, string drugo);
	~Utakmica();

	string getDomacaEkipa() const;
	string getGostujucaEkipa() const;
	int getBrojGolovaDomaca() const;
	int getBrojGolovaGostujuca() const;

	/*void setDomacaEkipa(string domacaEkipa);
	void setGostujucaEkipa(string gostujucaEkipa);
	void setBrojGolovaDomaca(int brojGolovaDomaca);
	void setBrojGolovaGostujuca(int brojGolovaGostujuca);*/

	void dodajGol(const string imeEkipe);
};

