#include <vector>
#include <string>
#include "Prijatelj.h"
using namespace std;

class Zabava
{
private:
	vector<Prijatelj*> uzvanici;
	vector<Pice*> popisPica;
	double budzet;
public:
	Zabava(double budzet);
	~Zabava(void);

	void dodajPrijatelja(Prijatelj* prijatelj);
	void dodajPice(Pice* pice);

	double getBudzet();
	Prijatelj* getPrijatelj(int id);
	Pice* nadjiPice(int PiceId);

	void ispisiPopisZaKupnju();
};