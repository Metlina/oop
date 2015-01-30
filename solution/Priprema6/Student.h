#pragma once
#include <string>
using namespace std;

class Student
{
private:
	string prezime;
	int godina;
	double stipendija;
public:
	Student();
	Student(string prez, int god, double stip);

	/*GET*/
	string getPrezime() const;
	int getGodina() const;
	double getStipendija() const;

	/*SET*/
	void setPrezime(string prez);
	void setGodina(int god);
	void setStipendija(double stip);

	/*OPERATORS*/
	bool operator>(const Student& other) const;
	bool operator<(const Student& other) const;
	Student& operator+=(const double iznos);

	/*FRIEND*/
	friend ostream& operator<<(ostream& izlaz, const Student& stud);
	friend istream& operator>>(istream& ulaz, Student& stud);
};
