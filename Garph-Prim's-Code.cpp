
#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Graph
{
	// Ajaceny.list
	vector <pair<int,int> > *l;
	int v;

	public:

	Graph(int n)
	{
		v = n;
		l = new vector<pair<int,int>> [n];
		// 1->(a,w1), (b,w2), (c,w3)
		//  a,w1 b,w2 c,w3 will be a vector
		// of type pair of int int
		// and we are creating an array of vectors
		// v[0] ->(a,w1), (b,w2), (c,w3)
		// v[1]->(a,w1), (b,w2), (c,w3)
		// and so on
	}

	void addEdge(int x, int y, int w)
	{
		l[x].push_back({y,w,});
		l[y].push_back({x,w});
	}
	int prim_mst()
	{	// store 2 things 
		// if there is a node from x -- w ---> y (w = weight)
		// we will store w,y
		// Initialised a min heap
		priority_queue <pair<int,int>, vector<pair<int, int>>, greater<pair <int,int>>> Q;
		// keyword
		// another array
		// visited array that denotes wheather a node has
		// been included in MST or not
		bool *vis = new bool[v]{0};
		// visited

		int ans =0;

		//begin 
		Q.push({0,0}); // weight, node- greater pair

		while(!Q.empty())
		{
			//pick out the edge with min edge
			auto best = Q.top(); // the best edge 
								// with minimu value 
								// will be at the top
			
			Q.pop();

			// node to whihc this edge is directed to
			int to  = best.second;
			int weight = best.first;

			if(vis[to])
			{
				// discard the edge, and continue
				continue;
			}

			// otherwise take the current edge
			ans+=weight; 
			// mark the node as visited
			vis[to]=1;

			// add the new edges in the queue
			for(auto x : l[to])
			{
				if(vis[x.first]==0)
				{
					Q.push({x.second, x.first});
				}
			}

		}

		return ans;
	}
};
int main()
{
	int n,m;
	cin >> n >> m;

	Graph g(n);
	for(int i=0; i<m; i++)
	{
		int x,y,w;
		cin >> x >> y >> w;
		g.addEdge(x-1, y-1, w);
	}

	cout << g.prim_mst() << endl;
	return 0;
}

//g++ sample.cpp -std=c++11

