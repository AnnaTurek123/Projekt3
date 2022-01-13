#include <iostream>
#include "GraphHelper.h"

int main()
{
	vector<vector<int>> A = {
		//{1, 1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0}, //macierz zawierająca izolowany wierzchołek 
		//{0, -1, 1, 1, -1, 0, 0, 0, 0, -1, 0, 0, 0},
		//{0, 0, -1, 0, 0, 1, 0, 0, 0, 0, -1, 0, 0},
		//{0, 0, 0, -1, 1, 0, 0, -1, 0, 0, 0, -1, 0},
		//{0, 0, 0, 0, 0, -1, 1, 1, 0, 0, 0, 0, -1},
		//{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		//{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1}

		{1, 1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0}, //macierz zawierająca wierzchołek będący sąsiadem wszystkich
		{0, -1,  1,  1, -1,  0,  0,  0,  0, -1,  0,  0,  0},
		{0, 0, -1, 0, 0, 1, 0, 0, 0, 0, -1, 0, 0},
		{0, 0, 0, -1, 1, 0, 0, -1, 0, 0, 0, -1, 0},
		{0, 0, 0, 0, 0, -1, 1, 1, 0, 0, 0, 0, -1},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1}
	}; //Deklaracja i inicjalizacja macierzy incydencji (wektora wektorów liczb typu int)

	GraphHelper graph(A);// utworzenie obiektu typu GraphHelper i przekazaniu mu do konstruktora macierzy
	cout << "Checking neighbours of specific vertex..." << endl;
	graph.GetAllNeighboursOfSpecificVertex(); //wywołanie metody na obiekcie graph sprawdzającej sąsiadów poszczególnych wierzchołków
	cout << endl;
	cout << "Checking vertex with all neighbours..." << endl;
	graph.GetAllVertexesWhereInNeighoudOfAllVertexes(); //wywołanie metody na obiekcie graph sprawdzającej wierzchołki będące sąsiadami wszystkich wierzchołków
	cout << endl;
	cout << "Checking degrees out from all vertexes..." << endl;
	graph.GetDegreesOutFromAllVertexes(); //wywołanie metody na obiekcie graph sprawdzającej stopnie wychodzące z wierzchołków
	cout << endl;
	cout << "Checking degrees in to all vertexes..." << endl;
	graph.GetDegreesInToAllVertexes(); //wywołanie metody na obiekcie graph sprawdzającej stopnie przchodzące do wierzchołka
	cout << endl;
	cout << "Checking isolated vertexes..." << endl;
	graph.GetAllIsolatedVertexes(); //wywołanie metody na obiekcie graph sprawdzającej izolowane wierzchołki
	cout << endl;
	cout << "Checking loops..." << endl;
	graph.GetAllLoops(); //wywołanie metody na obiekcie graph sprawdzającej pętle
	cout << endl;
	cout << "Checking two way edges..." << endl;
	graph.GetAllTwoWayEdges(); //wywołanie metody na obiekcie graph sprawdzającej dwukierunkowe krawędzie
}