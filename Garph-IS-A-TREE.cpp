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
		l[y].push_back(x);
	}
	bool is_tree()
	{
		bool *visited = new bool[v];
		int *parent = new int[v];
		queue<int> q;
		for(int i=0; i<v; i++)
		{
			visited[i]=false;
			parent[i]=i;
		}

		int src =0;

		q.push(src);
		visited[src] = true;

		// pop out eac node
		while(!q.empty())
		{
			int node = q.front();
			q.pop();

			for(int nbr:l[node])
			{
				if(visited[nbr]==true && parent[node]!=nbr)
				{
					return false;
				}
				else if(!visited[nbr])
				{
					visited[nbr]=true;
					parent[nbr]=node;
					q.push(nbr);
				}

			}

		}

		return true;
	}
};
int main()
{
	Graph g(4);
	g.addEgde(0,1);
	g.addEgde(3,2);
	g.addEgde(1,2);
//	g.addEgde(0,3);
	
	if(g.is_tree())
	{
		cout << "Yes, it is a tree" << endl;
	}
	else
	{
		cout << "Not a tree" << endl;
	}
	
	return 0;
}

//g++ sample.cpp -std=c++11