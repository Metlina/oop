#include <iostream>
#include <string>
using namespace std;

void print(int a, bool b, string c)
{
	if (a < 10) throw a;
	if (!b) throw b;
	if (c.at(0) == 'x') throw c;
	cout << a << " " << c << endl;
}

int main()
{
	try
	{
		print(5, true, "x");
	}
	catch (int e){ cout << e << endl; }
	catch (bool e){ cout << e << endl; } //Ispis bool vrijednosti ispisuje 0 ili 1
	catch (string e){ cout << e << endl; }
	catch (...){ cout << "other" << endl; }

	system("PAUSE");
	return 0;
}