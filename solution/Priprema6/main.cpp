#include "MZOS.h"
#include "Student.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& izlaz, const Student& stud)
{
	izlaz << stud.getPrezime() << " " << stud.getGodina() << ". " << stud.getStipendija() << endl;
	return izlaz;
}

istream& operator>>(istream& ulaz, Student& stud)
{
	ulaz >> stud.prezime >> stud.godina >> stud.stipendija;
	//ulaz >> stud.prezime >> stud.stipendija;
	return ulaz;
}

int main()
{
	int N, Q, S;
	
	//Unosi se broj studenata N
	cin >> N;

	//temp objekti
	MZOS mzos;
	Student stud;
	//Unosi se N studenata u obliku "<prezime> <godina> <iznos stipendije>"
	for (int i = 0; i < N; i++)
	{
		//Student stud;
		cin >> stud;
		mzos.dodajStudenta(stud);
	}

	//Unosi se broj izmjena Q
	cin >> Q;

	//Unosi se Q izmjena u obliku "<prezime> <iznos>" gdje je <prezime> kriterij po
	//kojem tražimo studenta kojem ćemo stipendiju uvećati za <iznos>
	for (int j = 0; j < Q; j++)
	{
		//Student stud;
		string prezime;
		double iznos;
		cin >> prezime >> iznos;
		Student *student = mzos.search(prezime);
		*student += iznos;
	}

	//Unosimo broj S
	cin >> S;

	/*for (int k = 0; k < S; k++)
	{
		mzos.ispisStudenta(k);
	}*/

	mzos.sortirajStudente();

	mzos.ispisStudenta(S);

	return 0;
}