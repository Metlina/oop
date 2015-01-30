#pragma once
#include<iostream>
#include<string>

using namespace std;

class Predmeti
{
private:
	string m_opis;
	double m_kolicina;
public:
	Predmeti()
	{
		m_opis = "NEMA PODATAKA";
		m_kolicina = 0;
	};

	Predmeti(string opis, double kolicina)
	{
		m_opis = opis;
		m_kolicina = kolicina;
	};

	~Predmeti();
};

