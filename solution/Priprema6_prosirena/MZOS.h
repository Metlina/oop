#pragma once
#include <string>
#include <vector>
#include "Student.h"
using namespace std;

class MZOS
{
private:
	vector<Student> studenti;
public:
	MZOS();

	void dodajStudenta(Student& stud);
	void sortirajStudente();
	void ispisStudenta(int rb);
	Student* search(string& prez);
};
