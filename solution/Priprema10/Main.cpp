#include <iostream> 
#include <string> 
#include "Kalkulator.h" 
#include "IncorrectDataExc.h" 
#include "InvalidOperationExc.h" 

using namespace std;

int main()
{
	string s;
	getline(cin, s);

	try
	{
		Matematika::Kalkulator kalkulator;
		cout << kalkulator.izracunaj(s) << endl;
	}
	catch (Matematika::Exceptions::IncorrectDataExc)
	{
		cout << "Exception IncorrectData" << endl;
	}
	catch (Matematika::Exceptions::InvalidOperationExc)
	{
		cout << "Exception InvalidOperation" << endl;
	}

	system("PAUSE");

	return 0;
}