
#include<iostream>
#include<map>
#include<queue>
#include<list>
using namespace std;

// t = int 
// map<int, <int>>
template <typename T>
class Graph
{

		// node example 2 is the ket and 
		// the neighbours are the value
		// 2 -> 1,3
			// list stores the values

	map<T, list<T>> l;

	public:
	void addEdge(int x, int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void bfs(T src)
	{
		map<T, int> dist;
		queue<T> q;

		

		// all other nodes will have  INT_MAX
		for(auto node_pair : l)
		{
			T node = node_pair.first;
			dist[node]= INT_MAX; // unvisited node set to infinite 
		}
		q.push(src);
		dist[src]=0;

		while(!q.empty())
		{
			T node = q.front();
			q.pop();
		
			for(int nbr : l[node])
			{
				if(dist[nbr]==INT_MAX)
				{
					q.push(nbr);
					// mark the nbr as visited
					dist[nbr] = dist[node]+1; //
								// child of node +1
				}
			}
		}

		// Print the dist to every node
		for(auto node_pair : l)
		{
			T node = node_pair.first;
			int d = dist[node];
			cout << "Node " << node << " Dist from src " << d << endl;
		}
	}
};
int main()
{
	Graph <int> g;
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);

	g.bfs(0);
	return 0;
}

//g++ sample.cpp -std=c++11