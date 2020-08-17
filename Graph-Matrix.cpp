
#include<iostream>
#include<unordered_map>
#include<cstring>
#include<list>

using namespace std;


int main()
{
	int n,m;
	cin >> n >> m;

	// matrix from 1 to n
	// 0 is empty  
	int mat[n+1][n+1]={}; // initialized by 0 so we
							// keep it empty 
	//input the no of edges
	// for un-weighted graph
	// for(int i=0; i<n; i++)
	// {
	// 		int x,y;
	// 		cin >> x >> y;

	// 		mat[x][y]=1;
	// 		mat[y][x]=1; // undirected
	// }

	// For weighted Graph
	for(int i=0; i<n; i++)
	{
			int x,y,w; // weight = w
			cin >> x >> y >> w;

			mat[x][y]=w;
			mat[y][x]=w; // undirected
	}
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=n; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}
// g++ sample.cpp -std=c++11