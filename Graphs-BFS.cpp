
#include<iostream>
#include<map>
#include<queue>
#include<list>
using namespace std;

// t = int 
// map<int, <int>>
template <typename T> // map <int, list<int>>
// key  and value 
// since this is not a weighted graph

class Graph
{

		// node example 2 is the ket and 
		// the neighbours are the value
		// 2 -> 1,3
			// list stores the values

	map<T, list<T>> l;
	  // key - value
      // key - node visited | value - connected nodes to the node visited
	  // 1 - (2,3,0) example
	  		//	put the values in a list

	public:
	void addEdge(int x, int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void bfs(T src)
	{
		map<T, int> visited;
		queue<T> q;

		q.push(src);
		visited[src]=true;

		while(!q.empty())
		{
			T node = q.front();
			q.pop();
			cout << node << " ";
			
			for(int nbr : l[node]) // gives the values of that node
			{
				if(!visited[nbr])
				{
					q.push(nbr);
					// mark the nbr as visited
					visited[nbr] = true;
				}
			}
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