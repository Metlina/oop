#include "Pravokutnik.h"

Pravokutnik::Pravokutnik(int a, int b, char boja) : a(a), b(b), GeomLik(boja, 2) {}

void Pravokutnik::ispisi()
{
	cout << "Pravokutnik, a=" << this->a << ", b=" << this->b << endl;
	for (int i = 0; i < this->a; i++)
	{
		for (int j = 0; j < this->b; j++)
		{
			cout << boja;
		}
		cout << endl;
	}
}
double Pravokutnik::getOpseg()
{
	return 2 * a + 2 * b;
}
double Pravokutnik::getPovrsina()
{
	return a * b;
}