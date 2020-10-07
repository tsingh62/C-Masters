
#include<iostream>
#include<list>

using namespace std;


class Graph
{
	int v;

	// Array of lists
	// l is a pointer to an array - in
    // which each element of the array is a list
	list<int> *l; // keeping l as a pointer to 
					// array of list
					// initialized during run time
	public:
	Graph(int v)
	{
		this->v = v;
		l = new list<int>[v];
	}

	void addEdge(int x, int y)
	{
		l[x].push_back(y); //  in the link list we are pushing 
		l[y].push_back(x); // the elements
	}
	void printAdjList()
	{
		// iterate over all vertices
		for(int i=0; i<v; i++)
		{
			cout << "vertex " << i << " -> ";
			for(int nbr : l[i])
			{
				cout << nbr << ", ";
			}
			cout << endl;
		}
	}
};



int main()
{
	Graph g(4); // 4 defines the no of edges
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(2,3);
	g.addEdge(1,2);
	g.printAdjList();

	return 0;
}
// g++ sample.cpp -std=c++11