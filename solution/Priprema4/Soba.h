#include <string>
#include <iostream>
using namespace std;

class Soba
{
private:
	string naziv;
	bool imaProzor;
public:
	Soba(void);
	Soba(string nazivSobe, string prozor);
	Soba(const Soba& soba);
	~Soba(void);

	void setProzor(string prozor);
	string getNaziv();
	void ispisiSobu();
};