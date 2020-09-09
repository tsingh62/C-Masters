
#include<iostream>
#include<unordered_map>
#include<cstring>
#include<list>

using namespace std;
// using hash-map
// weighted graph

/*(A)----20----(B)
    |\          |
    |  \        | 
    10    50     30
    |        \   |
    |         \  |
  (C)-----40----(D)

  A -> (B,20) (D,50) (C,10)
       --------------------
  A              |
  |              V
  String      List<pair> <String, int>>
  ------        --------------------
  Key               Value

*/ 


class Graph
{
	// Adj list
	unordered_map<string, list<pair<string, int> > > l;
				// key	//--- value ----------//
	public:
	void addEdge(string x, string y, bool bidir, int wt)
	{								// bi directional

		l[x].push_back(make_pair(y, wt));
		if(bidir)
		{
			l[y].push_back(make_pair(x, wt));
		}
	}
	void printAdjList()
	{
		// iterate over all th ekeys in the map
		for(auto p :l)
		{
			string city = p.first;
			list<pair<string, int > > nbrs = p.second;

			cout << city << "-> ";
			for(auto nbr : nbrs)
			{
				string dest = nbr.first;
				int dist = nbr.second;

				cout << dest << " " << dist << ",";
			}
			cout << endl;
		}
	}
};

int main()
{
	Graph g;
	g.addEdge("A","B", true, 20);
	g.addEdge("B","D", true, 40);
	g.addEdge("A","C", true, 10);
	g.addEdge("C","D", true, 40);
	g.addEdge("A","D", false, 20);
	g.printAdjList();
	return 0;
}
// g++ sample.cpp -std=c++11