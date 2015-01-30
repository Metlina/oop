#include "Kvadrat.h"

Kvadrat::Kvadrat(int a, char boja) : a(a), GeomLik(boja, 1) {}

void Kvadrat::ispisi()
{
	cout << "Kvadrat, a=" << this->a << endl;
	for (int i = 0; i < this->a; i++)
	{
		for (int j = 0; j < this->a; j++)
		{
			cout << boja;
		}
		cout << endl;
	}
}
double Kvadrat::getOpseg()
{
	return 4 * a;
}
double Kvadrat::getPovrsina()
{
	return a * a;
}