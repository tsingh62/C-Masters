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
	void addEdge(T x, T y)
	{
		l[x].push_back(y);
	//	l[y].push_back(x);
	}
	void dfs_helper(T src, map<T, bool> &visited,
			list<T> &ordering)
	{
		// Rec function that will traverse the graph

		// cout << src << " ";
		visited[src]=true;
		// goto negihbour of that node
		// that is not visited
		for(T nbr : l[src])
		{
			if(!visited[nbr])
			{
				//Rec
				  dfs_helper(nbr, visited, ordering);
			}
		}
		// at this point
		ordering.push_back(src);
		return;
	}

	void dfs()
	{
		map<T, bool> visited;
		// mark all the nodes as
		// not visited in the begining
		list<T> ordering;

		for(auto p : l)
		{
			T node = p.first;
			visited[node] = false;
		}
		// Iterate over all the vertices 
        // and init a dfs call
       
        
        for(auto p : l)
        {
            T node = p.first;
            
            if(!visited[node])
            {
                dfs_helper(node, visited, ordering);
            }
        }
		// finally or print the list
		for(auto node : ordering)
		{
			cout << node << endl;
		}
		
	}
};
int main()
{
	Graph <string> g;
	g.addEdge("Python","DataProgrocessing");
	g.addEdge("Python","PyTorch");
	g.addEdge("Python","ML");
	g.addEdge("DataProgrocessing","ML");
	g.addEdge("PyTorch","DL");
	g.addEdge("ML","DL");
	g.addEdge("DL","FaceREcogn");
	g.addEdge("DataSet","FaceREcogn");


	g.dfs();
	return 0;
}

//g++ sample.cpp -std=c++11