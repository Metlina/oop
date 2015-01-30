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
bool Student::operator>(const Student& other) const
{
	if (this->godina > other.godina)
		return true;
	if (this->godina < other.godina)
		return false;
	if (this->stipendija > other.stipendija)
		return true;
	if (this->stipendija < other.stipendija)
		return false;
	if (this->prezime[0] < other.prezime[0])
		return true;
	if (this->prezime[0] > other.prezime[0])
		return false;

	return false;
}
bool Student::operator<(const Student& other) const
{
	if(this->godina < other.godina)
		return true;
	if (this->godina > other.godina)
		return false;
	if (this->stipendija < other.stipendija)
		return true;
	if (this->stipendija > other.stipendija)
		return false;
	if (this->prezime[0] > other.prezime[0])
		return true;
	if (this->prezime[0] < other.prezime[0])
		return false;

	return false;
}
Student& Student::operator+=(const double iznos)
{
	this->stipendija += iznos;
	return *this;
}