
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<list>
#include<set>
using namespace std;



vector<int> bellman_ford(int n, int src, vector<vector<int>> edges)
{
	// min-dis from source to i
	// d(src,i)
	vector<int> dis(n+1, INT_MAX);
	dis[src]=0;

	// relax all the edges n-1 times
	for(int i=0; i<n-1; i++)
	{
		for(auto x : edges)
		{
			int from=x[0], to=x[1], weight=x[2];
			// relaxing an edge
			if(dis[from]!= INT_MAX && dis[to]>dis[from]+weight)
			{
				// relaxed the edge
				dis[to]=dis[from]+weight;
			}
		}
	}
	// lets check for negative weight cycle
	for(auto x : edges)
		{
			int from=x[0], to=x[1], weight=x[2];
			// relaxing an edge
			if(dis[from]!= INT_MAX && dis[to]>dis[from]+weight)
			{
				cout << "Negative weight cycle";
				exit(0);
			}
		}

		return dis;
}

int main()
{
	int n,m;
	cin >> n >> m;

	vector<vector<int>> edges;

	for(int i=0; i<m; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		edges.push_back({from,to,weight});
	}

	vector<int> dis = bellman_ford(n, 1, edges);
								// src = 1
	for(int i=0; i<=n; i++)
	{
		cout << "Distance from src to i " << i <<" is " << dis[i] << '\n';
	}
}
//g++ sample.cpp -std=c++11

// input
//3 3
//1 2 4
//1 3 5
//3 2 -7

// input for - Negative weight cycle
// 3 3
// 2 1 -4
// 1 3 5
// 3 2 -7