#pragma once
#include "vertex.h"
#include "List.h"
#include <cstdlib>
#include <iostream>


class Graph
{
public:

	vertex* arrayOfVertex;
	double P;
	int numOfVertex = 0;


	void MakeEmptyGraph(int numberOfVer);
	bool IsAdjacent(int u, int v);
	List* getAdjList(int u);
	void RemoveEdge(int u, int v);

	Graph() {
		//std::cin >> numOfVertex;
		//std::cin >> P;
		numOfVertex = 1024;
		//P = 0.015625;
		ReadGraph();
	}
;
	Graph(const Graph& graph)
	{
		numOfVertex = graph.numOfVertex;
		arrayOfVertex = new vertex[numOfVertex];
		for (int i = 0; i < numOfVertex; i++) {
			this->arrayOfVertex[i] = graph.arrayOfVertex[i];
			this->arrayOfVertex[i].listOfneighbor = new List();
			List::node* curr = graph.arrayOfVertex[i].listOfneighbor->head;
			while (curr)
			{
				arrayOfVertex[i].listOfneighbor->addToHead(curr->vertexNumber);
				curr = curr->next;
			}
		}
	}
	Graph(int sizeOfVertex, int i_startVertex, int i_destVertex)
	{
		numOfVertex = sizeOfVertex;
		arrayOfVertex = new vertex[numOfVertex];
	}
	~Graph()
	{
		for (int i = 0; i < numOfVertex; i++)
		{
			delete (arrayOfVertex[i].listOfneighbor);
		}
		
	}
	void ReadGraph();
	void PrintGraph();
	int isEmpty();
	int AddEdge(int i, int j);
	void deleteAdj(int vertexFrom, int numToDelete);
	bool isValidEdge(int i, int j);
	double* PageRank(int N, double epsilon, int t);
	void addHatutuert(int  num_to_add);
};

