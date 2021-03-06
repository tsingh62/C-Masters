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

		// node example 2 is the key and 
		// the neighbours are the value
		// 2 -> 1,3
			// list stores the values

	map<T, list<T>> l;

	public:
	void addEdge(int x, int y)
	{
		l[x].push_back(y);
	//	l[y].push_back(x);
	}
	void dfs_helper(T src, map<T, bool> &visited)
	{
		// Rec function that will traverse the graph

		cout << src << " ";
		visited[src]=true;
		// goto negihbour of that node
		// that is not visited
		for(T nbr : l[src])
		{
			if(!visited[nbr])
			{
				//Rec
				  dfs_helper(nbr, visited);
			}
		}
	}

	void dfs()
	{
		map<T, bool> visited;
		// mark all the nodes as
		// not visited in the begining

		for(auto p : l)
		{
			T node = p.first;
			visited[node] = false;
		}
		// Iterate over all the vertices 
        // and init a dfs call
       
        int cnt =0;
        for(auto p : l)
        {
            T node = p.first;
            

            if(!visited[node])
            {
                cout << "Component " << cnt << "--->";
                dfs_helper(node, visited);
                cnt++;
                cout << endl;
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
	g.addEdge(0,3);
	g.addEdge(0,4);

	g.addEdge(5,6);
    g.addEdge(6,7);

    g.addEdge(8,8);

	g.dfs();
	return 0;
}

//g++ sample.cpp -std=c++11