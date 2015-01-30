#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Predmeti.h"

using namespace std;

class Plaza
{
private:
	int m_velicina;
	double m_gpsX;
	double m_gpsY;
	vector<Predmeti> m_dostupni;
public:
	Plaza()
	{
		m_velicina = 0;
		m_gpsX = 0;
		m_gpsY = 0;
		m_dostupni.reserve(100);
	};

	Plaza(int velicina, double gpsX, double gpsY)
	{
		m_velicina = velicina;
		m_gpsX = gpsX;
		m_gpsY = gpsY;
		m_dostupni.reserve(100);
	};

	void dodajVelicinuILokaciju()
	{
		
	}

	void dodajPredmet(Predmeti predmet)
	{
		m_dostupni.push_back(predmet);
	}

	void ispisPlazaIPredmeta()
	{
		
	}

	~Plaza();
};

