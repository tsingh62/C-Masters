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

	void addEgde(int x, int y)
	{
		l[x].push_back(y);
	}
	void topological_sort()
	{
		// create array of indegree
		int *indegree = new int[v];
		for(int i=0; i<v; i++)
		{
			indegree[i]=0;
		}
		// update indegree by traversing edges 
		// x -->y
		// indegree[y] ++
		for(int i=0; i<v; i++)
		{
			
			for(auto y:l[i])
			{
				indegree[y]++;
			}
		}
		// bfs
		queue<int>	q;
		//1.step find nodes with 0 indegree

		for(int i=0; i<v; i++)
		{
			if(indegree[i]==0)
			{
				q.push(i);
			}
		}
		// start removing elements from the queue - BFS
		while(!q.empty())
		{
			int node = q.front();
			cout << node << " ";
			q.pop();
		
		// iterate over nbrs of that node and reduce their indegre
		// by 1
		for(auto nbr:l[node])
		{
			indegree[nbr]--;
			if(indegree[nbr]==0)
			{
				q.push(nbr);
			}
		}
	} 
}
};
int main()
{
	Graph g(5);
	g.addEgde(0,2);
	g.addEgde(0,1);
	g.addEgde(1,2);
	g.addEgde(2,3);
	g.addEgde(3,4);
	g.addEgde(4,5);
	g.addEgde(3,0);
	
	g.topological_sort();
	return 0;
}

//g++ sample.cpp -std=c++11