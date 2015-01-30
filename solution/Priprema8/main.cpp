#include <iostream>
#include "Crtanka.h"
using namespace std;

int main()
{
	Crtanka ploca;

	int n;
	cin >> n;

	char izbor, boja;
	GeomLik* likPtr;
	int num1, num2;
	for (int i = 0; i<n; i++)
	{
		cin >> izbor;
		switch (izbor)
		{
		case 'K':
		{
			cin >> num1 >> boja;
			likPtr = new Kvadrat(num1, boja);
			ploca.dodajLik(likPtr);
			break;
		}
		case 'P':
		{
			cin >> num1 >> num2 >> boja;
			likPtr = new Pravokutnik(num1, num2, boja);
			ploca.dodajLik(likPtr);
			break;
		}
		default:
		{
			cout << "Krivi unos!" << endl;
			break;
		}
		}
	}

	int p, trazeniID;
	char novaBoja;
	GeomLik* trazeniLikPtr;
	cin >> p;
	for (int j = 0; j<p; j++)
	{
		cin >> trazeniID >> novaBoja;
		trazeniLikPtr = ploca.getLik(trazeniID);

		trazeniLikPtr->setBoja(novaBoja);
	}

	ploca.ispisiSveLikove();

	cout << endl;
	cout << "Opseg svih likova: " << ploca.getUkupanOpseg() << endl;
	cout << "Povrsina svih likova: " << ploca.getUkupnuPovrsinu() << endl;
}