#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Pacijent.h"

using namespace std;

class SistematskiPregled
{
	//clanske varijable
private:
	vector<Pacijent> m_popisPacijenta;
	vector<string> m_popisPretraga;
	string m_imeDoktora;
	string m_prezimeDoktora;
	string m_datum;
	string m_vrijeme;
public:
	//konstruktori
	SistematskiPregled()
	{
		m_imeDoktora = "NEMA PODATAKA";
		m_prezimeDoktora = "NEMA PODATAKA";
		m_datum = "NEMA PODATAKA";
		m_vrijeme = "NEMA PODATAKA";
		m_popisPacijenta.reserve(25);
		m_popisPretraga.reserve(25);
	}
	SistematskiPregled(string imeDoktora, string prezimeDoktora)
	{
		m_imeDoktora = imeDoktora;
		m_prezimeDoktora = prezimeDoktora;
		m_datum = "NEMA PODATAKA";
		m_vrijeme = "NEMA PODATAKA";
		m_popisPacijenta.reserve(25);
		m_popisPretraga.reserve(25);
	}
	//destruktor
	~SistematskiPregled()
	{
		//m_popisPacijenta.clear();
		//m_popisPretraga.clear();
	};
	
	//metode
	//postaviVrijemePregleda(string datum, string vrijeme) - postavlja atribute datum i vrijeme na nove vrijednosti
	void postaviVrijemePregleda(string datum, string vrijeme)
	{
		m_datum = datum;
		m_vrijeme = vrijeme;
	}
	//dodajPacijenta(Pacijent noviPacijent) - dodaje novog pacijenta u popisPacijenata
	void dodajPacijenta(Pacijent noviPacijent)
	{
		m_popisPacijenta.push_back(noviPacijent);
	}
	//dodajPretragu(string novaPretraga) - dodaje novu pretragu u popisPretraga
	void dodajPretragu(string novaPretraga)
	{
		m_popisPretraga.push_back(novaPretraga);
	}
	//ispisiOsnovnePodatke() - metoda koja ispisuje osnovne podatke o pregledu kao u testnom primjeru, te potpuni popis pacijenata, numeriran
	void ispisiOsnovnePodatke()
	{
		cout << "Sistematski pregled - dr. " << m_imeDoktora << " " << m_prezimeDoktora << endl;
		cout << "Vrijeme odrzavanja: " << m_datum << ", " << m_vrijeme << " sati." << endl;
		cout << "Popis pacijenata:" << endl;
		int brojac;
		int n = 1;
		for (brojac = 0; brojac < m_popisPacijenta.size(); brojac++)
		{
			cout << n << ". " << m_popisPacijenta.at(brojac).ime << " " << m_popisPacijenta.at(brojac).prezime << ", rodjen/a " << m_popisPacijenta.at(brojac).datumRodjenja << endl;
			n++;
		}
	}
	//ispisiPacijentePrvoSlovo(char prvoSlovo) - ispisuje pacijente èije prvo slovo imena odgovara danom characteru
	void ispisiPacijentePrvoSlovo(char prvoSlovo)
	{
		char slovo = prvoSlovo;
		int i;
		cout << "Pacijenti cije ime pocinje s " << slovo << ":" <<endl;
		for (i = 0; i < m_popisPacijenta.size(); i++)
		{
			if (m_popisPacijenta.at(i).ime.find_first_not_of(slovo))
				cout << m_popisPacijenta.at(i).ime << " " << m_popisPacijenta.at(i).prezime << ", rodjen/a " << m_popisPacijenta.at(i).datumRodjenja << endl;
		}
	}
	//ispisiPretrage() - ispisuje sve pretrage u jednom redu, odvojene zarezom
	void ispisiPretrage()
	{
		int j, k;
		cout << "Obavljene pretrage:" << endl;
		for (j = 1; j < m_popisPretraga.size(); j++)
		{
			cout << m_popisPretraga[j-1] << ", ";
		}
		for (k = (m_popisPretraga.size()-1); k < m_popisPretraga.size(); k++)
		{
			cout << m_popisPretraga[k] << endl;
		}
	}
};