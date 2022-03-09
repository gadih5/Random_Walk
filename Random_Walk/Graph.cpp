#include "Graph.h"
void  Graph::MakeEmptyGraph(int numberOfVer) {
	numOfVertex = numberOfVer;
	arrayOfVertex = new vertex[numberOfVer];
	for (int i = 0; i < numberOfVer; i++) {
		arrayOfVertex[i] = vertex(i + 1);
	}
}
bool  Graph::IsAdjacent(int u, int v) {
	return arrayOfVertex[u - 1].listOfneighbor->isExist(v);

}
List* Graph::getAdjList(int u)
{
	return(arrayOfVertex[u - 1].listOfneighbor);
}
void  Graph::RemoveEdge(int u, int v) {
	arrayOfVertex[u - 1].listOfneighbor->deleteNode(v);
}


void Graph::ReadGraph()
{
	arrayOfVertex = new vertex[numOfVertex];
	for (int i = 0; i <= numOfVertex; i++)
	{
		arrayOfVertex[i].verNumber = i + 1;
	}


	for (int from = 1; from <= numOfVertex; from++) {
		for (int to = 1; to <= numOfVertex; to++) {
			double random= (double)rand() / RAND_MAX;
			double P = 1 / log(from + 1);
			if (random <= P) {
				arrayOfVertex[from - 1].listOfneighbor->addToHead(to);
				arrayOfVertex[from - 1].numOfNeighbor++;
				arrayOfVertex[from - 1].rank++;
				arrayOfVertex[to- 1].rank++;
			}
		}
	
	}

}
void Graph::PrintGraph() {
	if (numOfVertex == 0)
	{
		std::cout << "Graph Empty" << std::endl;
		return;
	}
	else {
		for (int i = 0; i < numOfVertex; i++) {
			List::node* p = arrayOfVertex[i].listOfneighbor->head;
			std::cout  << i + 1 << " -> ";
			while (p != nullptr) {
				std::cout  << p->vertexNumber << " ->";
				p = p->next;

			}
			std::cout << "null\t"<<std::endl;

		}
	}
}
int  Graph::isEmpty()
{
	return numOfVertex > 0 ? 0 : 1;
}
int  Graph::AddEdge(int i, int j)
{
	if (isValidEdge(i, j)) {
		arrayOfVertex[i - 1].addneighbor(j);
		return 1;
	}
	else
	{
		return 0;

	}
}
void Graph::deleteAdj(int vertexFrom, int numToDelete)
{
	arrayOfVertex[vertexFrom - 1].listOfneighbor->deleteNode(numToDelete);

}
bool Graph::isValidEdge(int i, int j)
{

	return(i<1 || i>numOfVertex || j<1 || j>numOfVertex);
}

double* Graph::PageRank(int N, double epsilon, int t)
{
	double* D = new double[numOfVertex];
	for (int y = 0; y < numOfVertex; y++) {
		D[y] = 0;
	}
	for (int i = 0; i < t; i++) {
		int randomVertex = 1 + (rand() % this->numOfVertex);
		for (int j = 0; j < N; j++) {
			double chanceOfEpsilon = (double)rand() / RAND_MAX;
			if (chanceOfEpsilon >= epsilon && this->arrayOfVertex[randomVertex - 1].numOfNeighbor != 0) {

				int randonIndexOfNeighborFromList = 1 + rand() % this->arrayOfVertex[randomVertex - 1].numOfNeighbor;

				List::node* temp = this->arrayOfVertex[randomVertex - 1].listOfneighbor->head;
				for (int k = 0; k < randonIndexOfNeighborFromList - 1; k++) {
					temp = temp->next;
				}
				randomVertex = temp->vertexNumber;
			}
			else {
				randomVertex = 1 + (rand() % this->numOfVertex);
			}

		}

		D[randomVertex - 1]++;
	}
	for (int i = 0; i < numOfVertex; i++) {
		D[i] = D[i] / t;
	}
	return D;
}

void Graph::addHatutuert(int NumToAdd)
{
	int randomVer = 1024;
	int randomVer2 = (rand() %  NumToAdd) + numOfVertex + 1;
	vertex* newVerArray = new vertex[numOfVertex + NumToAdd];
	for (int i = 0; i < numOfVertex + NumToAdd; i++) {
		if (i < numOfVertex) {
			newVerArray[i] = this->arrayOfVertex[i];
			newVerArray[i].listOfneighbor = this->arrayOfVertex[i].listOfneighbor;
			
		}
		else {
			newVerArray[i].verNumber = i + 1;

			
		}
	}
	for (int i = numOfVertex; i < numOfVertex + NumToAdd; i++) {
			newVerArray[i-1].listOfneighbor->addToHead(i + 1);
			newVerArray[i - 1].numOfNeighbor++;
			newVerArray[i - 1].rank++;
			newVerArray[i].rank++;
	}

	newVerArray[numOfVertex + NumToAdd -1].listOfneighbor->addToHead(numOfVertex  + 1);
	newVerArray[numOfVertex + NumToAdd - 1].numOfNeighbor++;
	newVerArray[numOfVertex + NumToAdd - 1].rank++;
	newVerArray[numOfVertex ].rank++;
	newVerArray[randomVer-1].listOfneighbor->addToHead(randomVer2);
	newVerArray[randomVer - 1].numOfNeighbor++;
	newVerArray[randomVer - 1].rank++;
	newVerArray[randomVer2 - 1].rank++;
	this->arrayOfVertex = newVerArray;
	this->numOfVertex = numOfVertex + NumToAdd;
}

