#pragma once
#include <string>
using namespace std;
class GeomLik
{
protected:
	char boja;
	int brojStranica;
public:
	GeomLik(char boja, int brojStranica) :boja(boja), brojStranica(brojStranica) { }

	int getBrojStranica() { return brojStranica; }
	char getBoja() { return boja; }
	void setBoja(char novaBoja) { boja = novaBoja; }

	virtual void ispisi() = 0;
	virtual double getOpseg() = 0;
	virtual double getPovrsina() = 0;
};