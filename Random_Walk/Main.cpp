#include "Graph.h"	
#include "List.h"
#include"Vertex.h"
#include <cmath>
#include <iostream>
//
double diffOfVectors(double* d, double* h, int size);
void copy(double* d, double* h, int size);
void myMain();
double epsilon = 0.5;
int N = 2 / epsilon;
int t = 2;
using namespace std;
int main() {
	for (int i = 0; i < 10; i++)
	{
		myMain();
		epsilon *= 0.5;
		N = 2 / epsilon;
	}

}
void copy(double* d, double* h, int size) {
	for (int i = 0; i < size; i++) {
		d[i] = h[i];
	}
}

void myMain()
{
	Graph g;
	double res = 1;
	double* h = nullptr;
	g.addHatutuert(64);
	t = 2;



	double* d = g.PageRank(N, epsilon, t);
	double sum = 0;
	int sum_of_degree = 0;


	while (res >= (1 / pow(2, 8))) {
		t = t * 2;
		cout << "t: " << t << endl;
		h = g.PageRank(N, epsilon, t);
		res = diffOfVectors(d, h, g.numOfVertex);
		for (int i = 0; i < g.numOfVertex; i++) {

			sum_of_degree += g.arrayOfVertex[i].rank;
		}
		cout << "epsilon = " << epsilon << endl;
		cout << "N = " << N << endl;
		cout << "The average rank of the vertices: ";
		cout << sum_of_degree / g.numOfVertex << endl;
		cout << "The diff is: " << res << endl;
		copy(d, h, g.numOfVertex);
	}
	double sumRankNonCircle = 0;
	double sumRankCircle = 0;
	for (int i = 0; i < 1024; i++) {

		sumRankNonCircle += d[i];
	}
	for (int i = 1024; i < 1088; i++) {

		sumRankCircle += d[i];
	}
	cout << "The average rank of the non-circle vertices: ";
	cout << sumRankNonCircle / 1024 << endl;
	cout << "The average rank of the circle vertices: ";
	cout << sumRankCircle / 64 << endl;

	//g.PrintGraph();
	//for (int i = 0; i < g.numOfVertex; i++) {
	//
	//	cout << "#" << i + 1  <<" " << d[i] << endl;
	//	sum = sum + d[i];
	//}
	//cout << "The sum Of all The vector coordinates is : " << sum << endl;

	delete[] h;
	delete[]d;
}

double diffOfVectors(double* d, double* h, int size) {
	double* temp = new double[size];
	double sum = 0;
	for (int i = 0; i < size; i++) {
		temp[i] = d[i] - h[i];
		sum += (pow(temp[i], 2));
	}
	delete[]temp;
	return pow(sum, 0.5);

}