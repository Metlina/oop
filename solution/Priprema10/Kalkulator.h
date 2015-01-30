#pragma once
#include "IncorrectDataExc.h"
#include "InvalidOperationExc.h"
#include <string>
#include <sstream>
#include <typeinfo>
#include <stdlib.h>

using namespace std;

namespace Matematika
{
	class Kalkulator
	{
	private:
		int rjesenje;
	public:
		//Kalkulator();
		//Podrzavaju se samo cjelobrojna djeljenja(ona koja daju cjelobrojni rezultat)
		//Podrzavaju se samo operacije +, -, * i /
		//Svi operandi moraju biti numerički
		//Podrzavaju se samo cjelobrojna djeljenja (ona koja daju cjelobrojni rezultat)
		int izracunaj(string s)
		{
			int broj1 = 0, broj2 = 0;
			char operacija;

			istringstream(s) >> broj1 >> operacija >> broj2;

			/*if ((typeid(broj1) != typeid(int)) || (typeid(broj2) != typeid(int)))
			{
				throw Matematika::Exceptions::IncorrectDataExc();
			}*/

			/*if (typeid(broj2) != typeid(int))
			{
				throw Matematika::Exceptions::IncorrectDataExc();
			}*/

			char  *p;
			if (long int provjera = strtol(s.c_str(), &p, 10))
			{
				*p == 0;
			}
			/*while (*p != '\0')
			{
				if (*p > 'a' || *p < 'z')
					throw Matematika::Exceptions::IncorrectDataExc();
			}*/
			/*if (broj2 == 0)
			{
				throw Matematika::Exceptions::IncorrectDataExc();
			}*/
			if (*p == 0)
			{
				throw Matematika::Exceptions::IncorrectDataExc();
			}
			else if (operacija == '+')
			{
				rjesenje = broj1 + broj2;
			}
			else if (operacija == '-')
			{
				rjesenje = broj1 - broj2;
			}
			else if (operacija == '*')
			{
				rjesenje = broj1 * broj2;
			}
			else if (operacija == '/')
			{
				if (broj2 == 0)
					throw Matematika::Exceptions::IncorrectDataExc();
				if (broj1 % broj2 != 0)
					throw Matematika::Exceptions::IncorrectDataExc();
				else
					rjesenje = broj1 / broj2;
			}
			else
				throw Matematika::Exceptions::InvalidOperationExc();

			return rjesenje;
		}
	};

}