#include <string>
#include <iostream>
using namespace std;

class Kuhinja
{
private:
	string bojaKuhinje;
	int brojPlamenika;
	bool imaPerilicu;
public:
	Kuhinja(void);
	Kuhinja(string boja, int plamenici, string perilica);
	Kuhinja(const Kuhinja& kuhinja);
	~Kuhinja(void);

	void setBrojPlamenika(int broj);
	void setBojaKuhinje(string boja);
	void setPerilica(string perilica);
	void ispisiKuhinju();
};