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
	bool cycle_helper(int node, bool *visited, bool *stack)
	{
		// visit a nodes
			visited[node] = true;
			stack[node] = true;

			for(int nbr : l[node])
			{
				// two cases
				if(stack[nbr]==true)
				{
				return true;
				}
				// 4 will return to 3 the cycle is found
				// 3 will return to 2 the cycle is found
				// as so on 2 to 1, and 1 to 0 
			else if(visited[nbr]==false)
			{
				bool cycle_mila = cycle_helper(nbr, visited, stack);
				
				if(cycle_mila ==true)
				{
				return true;
			}
			}
			}
			// leave a node
			stack[node]=false;
			return false; //no cycle is present

	}
	bool contains_cycle()
	{
		bool *visited = new bool[v];
		// this is not a stck data structure
		// its just an array
		bool *stack = new bool[v];

		for (int i=0; i<v; i++ )
		{
			visited[i] = stack[i] = false;
		}
		return cycle_helper(0, visited, stack);
	}					// node is 0 here
	
};
int main()
{
	Graph g(7);
	g.addEgde(0,1);
	g.addEgde(1,2);
	g.addEgde(2,3);
	g.addEgde(3,4);
	g.addEgde(4,5);
	g.addEgde(1,5);
	g.addEgde(5,6);
	g.addEgde(4,2); // Back Edge
	
	if(g.contains_cycle())
	{
		cout << "Yes contains cycle" << '\n';
	}
	else
	{
		cout << "Does not contain a cycle" << '\n';
	}
	
	return 0;
}

//g++ sample.cpp -std=c++11