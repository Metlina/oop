#pragma once
#include "Utakmica.h"
#include <string>
#include <vector>

using namespace std;

class Skupina
{
private:
	vector<string> nizEkipa;
	vector<Utakmica> nizUtakmica;
public:
	Skupina();
	~Skupina();

	string getNizEkipa() const;
	Utakmica getNizUtakmica() const;

	/*void setNizEkipa();
	void setNizUtakmica();*/

	void dodajEkipu(string imeEkipe);
	string getEkipa(int i) const;
	Utakmica* getUtakmicu(const string domaca, const string gostujuca);

	void napraviZdrijeb();
	int izracunajBodove(const string imeEkipe) const;
};

