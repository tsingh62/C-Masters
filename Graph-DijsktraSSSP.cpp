
#include<iostream>
// #include<map>
#include<unordered_map>
#include<queue>
#include<list>
#include<set>
using namespace std;

// t = int 
// map<int, <int>>
template <typename T>
class Graph
{				// key 		// value	of list type
	unordered_map <T, list<pair<T, int>>> m;

	public:
	void addEdge(T u, T v, int dist, bool bldlr=true)
	{
		// starts from u and ends in v
		// edge from = delhi --- 5 --> mumbai
		// so we represnt it as
		// delhi ---->(mumbai, 5)// insert a pair called mumbai with value 5-dist
		// key 		// value	of list type
		m[u].push_back(make_pair(v, dist));
		//u is delhi and the pair has v as mumbi and dist 5

		// if the edge is bi-directional 
		if(bldlr)
		{
			m[v].push_back(make_pair(u, dist));
		}

	}
	
	void printAd()
	{
			// print the adjency list
			// iterate over all the key valus pairs in the map

			for(auto j : m)
			{
				// j - is an iterator which will refer to each object
				// j.first refers to Amristsar - 1st on the key 
				// j.second - refers to the list that is
				// Amristar ---> (delhi, 5)
				// that mean j.second is delhi
				cout << j.first << "--->";

				// iterate over the list of cities
				for(auto l : j.second)
				{
					cout << "(" << l.first <<"," << l.second << ")";
								// city and 	 //the distnace 
				}
				cout << endl;
			}
	}
	void dijsktraSSSP(T src)
	{
		// store the dist value 
		// dist <city, int>
		unordered_map <T, int> dist;

		// all distance sto infinity
		for(auto j : m)
		{
			dist[j.first] = INT_MAX;
		}
		// Make a set to find out node 
		// with a minimum distance
		set<pair<int, T> > s;
		// sorting in set according to the 1st parameter
		// cause here we are sorting according to the dist
		dist[src]=0;
		s.insert(make_pair(0,src));
				// dist of src is 0 
		while(!s.empty())
		{
			// Find the pair at the front 
			auto p = *(s.begin());
			T node = p.second; // denotes the node - second
			// and the 1st paramter denotes the distance

			int nodeDist = p.first;

			// once the dist has been finalised 
			// we have to delet / remove the node
			s.erase(s.begin());

			// iterate over neighbours/children of the current node
			for(auto childPair : m[node])
			{										// INT_MAX = set to infinity	
				if(nodeDist + childPair.second < dist[childPair.first])
							// 1 --> (2,1) second = 1 here is the edge 
											// between 1 and 2
			
			{
			 // In the set updation of a particular node is not possible
			 // we have to remove the old pair and 
			// insert the new pair to simulate an updation 
			T dest = childPair.first;
			auto f = s.find(make_pair(dist[dest], dest));
			if(f!=s.end())
			{
				s.erase(f); // if node found we erase it
			}

			// Insert the new pair
			dist[dest]= nodeDist + childPair.second; 
					// dist of parent 
			s.insert(make_pair(dist[dest], dest));
			}
			}

		}

	// print distance to all other nodes from source
		for(auto d : dist)
		{
		cout << d.first << " is located at distance of " << d.second << endl; // first -> city
		}
	}
};
int main()
{
	Graph <int> g;
	g.addEdge(1,2,1);
	g.addEdge(1,3,4);
	g.addEdge(2,3,1);
	g.addEdge(3,4,2);
	g.addEdge(1,4,7);

//	g.printAd();
//	g.dijsktraSSSP(1);


	Graph <string> India;
	India.addEdge("Amritsar","Delhi",1);
	India.addEdge("Amritsar","Jaipur",4);
	India.addEdge("Jaipur","Delhi",2);
	India.addEdge("Jaipur","Mumbai",8);
	India.addEdge("Bhopal","Agra",2);
	India.addEdge("Mumbai","Bhopal",3);
	India.addEdge("Agra","Delhi",1);

	// India.printAd();

	India.dijsktraSSSP("Amritsar");
	return 0;
}

//g++ sample.cpp -std=c++11