#pragma once
#include "GeomLik.h"
#include <iostream>

class Pravokutnik : public GeomLik
{
private:
	int a, b;
public:
	Pravokutnik(int a, int b, char boja);

	void ispisi();
	double getOpseg();
	double getPovrsina();
};

