#pragma once
#include "GeomLik.h"
#include <iostream>

class Kvadrat : public GeomLik
{
private:
	int a;
public:
	Kvadrat(int a, char boja);

	void ispisi();
	double getOpseg();
	double getPovrsina();
};

