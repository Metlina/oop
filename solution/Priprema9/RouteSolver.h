#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <list>

#include <limits> // for numeric_limits

#include <set>
#include <utility> // for pair
#include <algorithm>
#include <iterator>

#include <map>
#include <string>

using namespace std;

typedef int vertex_t;
typedef double weight_t;

const weight_t max_weight = std::numeric_limits<double>::infinity();

struct grad {
	vertex_t ruta;
	weight_t cijena;
	grad(vertex_t arg_target, weight_t arg_weight)
		: ruta(arg_target), cijena(arg_weight) { }
};

typedef std::vector<std::vector<grad> > lista_grad_t;


void racunaj(vertex_t source,
	const lista_grad_t &adjacency_list,
	std::vector<weight_t> &min_distance,
	std::vector<vertex_t> &previous)
{
	int n = adjacency_list.size();
	min_distance.clear();
	min_distance.resize(n, max_weight);
	min_distance[source] = 0;
	previous.clear();
	previous.resize(n, -1);
	std::set<std::pair<weight_t, vertex_t> > vertex_queue;
	vertex_queue.insert(std::make_pair(min_distance[source], source));

	while (!vertex_queue.empty())
	{
		weight_t dist = vertex_queue.begin()->first;
		vertex_t u = vertex_queue.begin()->second;
		vertex_queue.erase(vertex_queue.begin());

		// Visit each edge exiting u
		const std::vector<grad> &omiljeniGrad = adjacency_list[u];
		for (std::vector<grad>::const_iterator omiljeniGrad_iter = omiljeniGrad.begin();
			omiljeniGrad_iter != omiljeniGrad.end();
			omiljeniGrad_iter++)
		{
			vertex_t v = omiljeniGrad_iter->ruta;
			weight_t weight = omiljeniGrad_iter->cijena;
			weight_t distance_through_u = dist + weight;
			if (distance_through_u < min_distance[v]) {
				vertex_queue.erase(std::make_pair(min_distance[v], v));

				min_distance[v] = distance_through_u;
				previous[v] = u;
				vertex_queue.insert(std::make_pair(min_distance[v], v));
			}
		}
	}
}


std::list<vertex_t> najkraciPut(
	vertex_t vertex, const std::vector<vertex_t> &previous)
{
	std::list<vertex_t> path;
	for (; vertex != -1; vertex = previous[vertex])
		path.push_front(vertex);
	return path;
}

class RouteSolver
{
private:
	int *rute;
	int cnt;
	int cntrute;
	map <int, string> gradovi;
	map <int, string> omiljeniGradovi;
public:
	RouteSolver()
	{
		cnt = 0;
		cntrute = 0;
		gradovi[cnt++] = "Zagreb";
		rute = new int[10000000];
	}

	//dodaje se grad
	void DodajGrad(string imeGrada)
	{
		gradovi[cnt++] = imeGrada;
	}

	//dodaje se grad do kojeg će se računati ruta(omiljeni grad)
	void DodajOmiljeniGrad(int index)
	{
		omiljeniGradovi[index] = gradovi[index];
	}
	//dodaje se veza između dva grada(od polaznog do odredišnog grada se dolazi za određenu cijenu)
	void DodajPrijevoz(int indexPolazista, int indexOdredista, int cijena)
	{
		rute[cntrute++] = indexPolazista;
		rute[cntrute++] = indexOdredista;
		rute[cntrute++] = cijena;
	}

	//vraća tražene rezultate u obliku ključ - vrijednost(ime grada - kolika je cijena puta do tog grada; 
	//ako nije moguće doći do nekog omiljenog grada(cijena premašuje budžet), ne dodaje se u popis
	map<string, int> Rijesi(double budzet)
	{
		lista_grad_t lista_grad(cnt);

		for (int i = 0; i < cntrute; i += 3)
			lista_grad[rute[i]].push_back(grad(rute[i + 1], rute[i + 2]));

		vector<weight_t> najkraci_put;
		vector<vertex_t> prethodni;
		racunaj(0, lista_grad, najkraci_put, prethodni);

		map<int, string>::iterator it;
		map<string, int> tempGrad;

		for (it = omiljeniGradovi.begin(); it != omiljeniGradovi.end(); ++it)
		{
			list<vertex_t> put = najkraciPut(it->first, prethodni);
			
			if (budzet - najkraci_put[it->first] > 0)
				tempGrad[it->second] = najkraci_put[it->first];
			
		}
		return tempGrad;
	}
};