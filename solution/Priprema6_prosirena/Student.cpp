#include "Student.h"

Student::Student(){}
Student::Student(string prez, int god, double stip)
{
	this->prezime = prez;
	this->godina = god;
	this->stipendija = stip;
}

/*GET*/
string Student::getPrezime() const{ return this->prezime; }
int Student::getGodina() const{ return this->godina; }
double Student::getStipendija() const{ return this->stipendija; }

/*SET*/
void Student::setPrezime(string prez)
{
	this->prezime = prez;
}
void Student::setGodina(int god)
{
	this->godina = god;
}
void Student::setStipendija(double stip)
{
	this->stipendija = stip;
}

/*OPERATORS*/
bool Student::operator==(const string& prezime) const
{
	return (prezime == this->prezime);

	return false;
}
bool Student::operator<(const string& other) const
{
	return prezime < other;

	return false;
}
bool Student::operator<(const Student& other) const
{
	return prezime < other.prezime;

	return false;
}
bool Student::operator>(const string& other) const
{
	return prezime > other;

	return false;
}
bool Student::operator>(const Student& other) const
{
	return prezime > other.prezime;

	return false;
}
Student& Student::operator+=(const double iznos)
{
	this->stipendija += iznos;
	return *this;
}