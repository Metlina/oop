#pragma once
#include "Crtanka.h"
#include <cstdlib>
#include <math.h>

Crtanka::Crtanka(int rows, int cols, char kist, char pozadina)
{
	brRed = rows;
	brStup = cols;
	zadaniKist = kist;
	this->pozadina = pozadina;
	matrica = new char*[brRed]; 
	for (int i = 0; i < brRed; ++i) 
	{
		matrica[i] = new char[brStup]; 
	} 
	for (int i = 0; i<brRed; i++) 
	{
		for (int j = 0; j<brStup; j++) 
		{
			matrica[i][j] = pozadina; 
		} 
	}
}
Crtanka::~Crtanka(){}

void Crtanka::ispisi()
{
	for (int i = 0; i < brRed; i++)
	{
		for (int j = 0; j < brStup; j++)
		{
			cout << matrica[i][j];
		}
		cout <<  endl;
	}
}

void Crtanka::ocisti()
{
	matrica = NULL;
}

void Crtanka::noviKist(char noviKist)
{
	zadaniKist = noviKist;
}

bool Crtanka::jeUnutarOkvira(Tocka p)
{
	if (p.x >= brRed || p.y >= brStup || p.x < 0 || p.y < 0)
		return false;
	else
		return true;
}

char Crtanka::getBoja(Tocka p)
{
	for (int i = 0; i < brRed; i++)
	{
		for (int j = 0; j < brStup; j++)
		{
			return matrica[p.x][p.y];
		}
	}
}

void Crtanka::tocka(Tocka p)
{
	matrica[p.x][p.y] = zadaniKist;
}

void Crtanka::crta(Tocka p1, Tocka p2)
{
	int delta_x(p2.x - p1.x);
	signed char const ix((delta_x > 0) - (delta_x < 0));
	delta_x = std::abs(delta_x) << 1;

	int delta_y(p2.y - p1.y);
	signed char const iy((delta_y > 0) - (delta_y < 0));
	delta_y = std::abs(delta_y) << 1;

	tocka(Tocka(p1.x, p1.y));

	if (delta_x >= delta_y)
	{
		int error(delta_y - (delta_x >> 1));

		while (p1.x != p2.x)
		{
			if ((error > 0) && (error || (ix > 0)))
			{
				error -= delta_x;
				p1.y += iy;
			}

			error += delta_y;
			p1.x += ix;

			tocka(Tocka(p1.x, p1.y));
		}
	}
	else
	{
		int error(delta_x - (delta_y >> 1));

		while (p1.y != p2.y)
		{
			if ((error > 0) && (error || (iy > 0)))
			{
				error -= delta_y;
				p1.x += ix;
			}

			error += delta_x;
			p1.y += iy;

			tocka(Tocka(p1.x, p1.y));
		}
	}
}

void Crtanka::trokut(Tocka p1, Tocka p2, Tocka p3)
{
	crta(p1, p2);
	crta(p2, p3);
	crta(p1, p3);
}

void Crtanka::pravokutnik(Tocka p1, Tocka p2)
{
	crta(Tocka(p2.x, p2.y), Tocka(p1.x, p2.y));
	crta(Tocka(p2.x, p2.y), Tocka(p2.x, p1.y));
	crta(Tocka(p1.x, p1.y), Tocka(p1.x, p2.y));
	crta(Tocka(p1.x, p1.y), Tocka(p2.x, p1.y));
}

void Crtanka::kruznica(Tocka p, int radius)
{
	int x = radius, y = 0;
	int greska = 1 - x;

	while (x >= y)
	{
		if (jeUnutarOkvira(Tocka(x + p.x, y + p.y)))
			tocka(Tocka(x + p.x, y + p.y));
		if (jeUnutarOkvira(Tocka(y + p.x, x + p.y)))
			tocka(Tocka(y + p.x, x + p.y));
		if (jeUnutarOkvira(Tocka(-x + p.x, y + p.y)))
			tocka(Tocka(-x + p.x, y + p.y));
		if (jeUnutarOkvira(Tocka(-y + p.x, x + p.y)))
			tocka(Tocka(-y + p.x, x + p.y));
		if (jeUnutarOkvira(Tocka(-x + p.x, -y + p.y)))
			tocka(Tocka(-x + p.x, -y + p.y));
		if (jeUnutarOkvira(Tocka(-y + p.x, -x + p.y)))
			tocka(Tocka(-y + p.x, -x + p.y));
		if (jeUnutarOkvira(Tocka(x + p.x, -y + p.y)))
			tocka(Tocka(x + p.x, -y + p.y));
		if (jeUnutarOkvira(Tocka(y + p.x, -x + p.y)))
			tocka(Tocka(y + p.x, -x + p.y));
		y++;
		if (greska<0)
		{
			greska += 2 * y + 1;
		}
		else
		{
			x--;
			greska += 2 * (y - x + 1);
		}
	}
}

void Crtanka::poligon(vector<Tocka> kutovi)
{
	for (int i = 0; i < kutovi.size()-1; i++)
	{
		crta(kutovi[i], kutovi[i + 1]);
	}
	for (int j = kutovi.size()-1; j < kutovi.size(); j++)
	{
		crta(kutovi[0], kutovi[j]);
	}
}

void Crtanka::oboji(Tocka p, char novaBoja)
{
	char bojanka = getBoja(p);

	matrica[p.x][p.y] = novaBoja;
	if (p.y + 1<brStup && p.y + 1 < brStup)
	{
		if (matrica[p.x][p.y + 1] == bojanka)
			oboji(Tocka(p.x, p.y + 1), novaBoja);
	}
	if (p.x + 1<brRed && p.x + 1 < brRed)
	{
		if (matrica[p.x + 1][p.y] == bojanka)
			oboji(Tocka(p.x + 1, p.y), novaBoja);
	}
	if (p.y - 1 >= 0 && p.y - 1 < brStup)
	{
		if (matrica[p.x][p.y - 1] == bojanka)
			oboji(Tocka(p.x, p.y - 1), novaBoja);
	}
	if (p.x - 1 >= 0 && p.x - 1 < brRed)
	{
		if (matrica[p.x - 1][p.y] == bojanka)
			oboji(Tocka(p.x - 1, p.y), novaBoja);
	}
}

void Crtanka::napisi(Tocka p, string text)
{
	int z = 0, k = 0;
	for (int i = 0; i< text.size(); i++)
	{
		matrica[p.x][p.y + k] = text[z];
		k++, z++; 
	}
}