#include<iostream>
#include<map>
#include<queue>
#include<list>
#include<cstring>
using namespace std;

// t = int 
// map<int, <int>>

class Graph
{
	list <int> *l;
	int v;

	public:
	Graph(int v)
	{
		this->v = v;
		l = new list<int>[v];
	}

	void addEgde(int x, int y, bool directed = true)
	{
		l[x].push_back(y);
		
		if(!directed)
		{
			l[y].push_back(x);
		}
	}
	bool cycle_helper(int node, bool *visited,int parent)
	{
		visited[node]=true;

		for(auto nbr : l[node])
		{
			// two cases
			if(!visited[nbr])
			{
				// go and recursively visit the nbr
				bool cycle_mila = cycle_helper(nbr, visited, node);
				if(cycle_mila)
				{
					return true;
				}
			}
			// nbr is visited
			// but the nbr should not be equal to parent
			else if(nbr!=parent)
			{
				return true;
			}
		}
		return false; // cycle not present 
	}
	bool contains_cycle()
	{
		bool *visited = new bool[v];
		// this is not a stck data structure
		// its just an array
		
		for (int i=0; i<v; i++ )
		{
			visited[i] =  false;
		}
		return cycle_helper(0, visited, -1);
	}					// node is 0 here
	
};
int main()
{
	Graph g(5);
	g.addEgde(0,1);
	g.addEgde(1,2);
	g.addEgde(2,3);
	g.addEgde(3,4);
	//g.addEgde(4,0);
	
	
	if(g.contains_cycle())
	{
		cout << "Yes undirected graph contains cycle" << '\n';
	}
	else
	{
		cout << "Does not contain a cycle" << '\n';
	}
	
	return 0;
}

//g++ sample.cpp -std=c++11