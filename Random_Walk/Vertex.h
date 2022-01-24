#pragma once
#include "List.h"
class vertex
{
public:
	unsigned int verNumber = 0;
	unsigned int numOfNeighbor = 0;
	unsigned int rank=0;
	List* listOfneighbor;
public:
	int getNumber()
	{
		return verNumber;

	}

	vertex(int number)
	{
		verNumber = number;
		listOfneighbor = new List();
	}
	~vertex()
	{
		
	}
	void addneighbor(int numOfVertex)
	{
		listOfneighbor->addToHead(numOfVertex);
	}
	vertex()
	{
		listOfneighbor = new List();
	}
};

