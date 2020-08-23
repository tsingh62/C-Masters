
#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// DSU data structure
// Path Compressin - Union by Rank

class DSU
{
    int *parent;
    int *rank;

    public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        // parent -1, rank =1

        for(int i=0; i<n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find Func
    int find(int i)
    {
        // Base case
        if(parent[i]==-1)
        {
            return i;
        }
        //Otherwise
        return parent[i] = find(parent[i]);
    }

    // Unite (union)
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if(s1!=s2){
            //union by rank
            if(rank[s1]<rank[s2])
            {
                parent[s1] = s2;
                rank[s2]+=rank[s1];
            }
            else
            {
                parent[s2]=s1;
                rank[s1] += rank[s2];
            }
            
        }
    }

};

class Graph
{
    vector<vector<int>> edgelist;
    // there is an edge from x->y with a weight w
    // (x,y,) with a weight of w1, so i have to save a list of triplets
    int v; // vertices

    public:
    Graph(int v)
    {
        this->v = v;
    }
    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({w,x,y});
        // we are taking w 1st as when we 
        // do sorting, weight would be considered 1st

    }
    int kruskal_mst()
    {
        // main logic
        //1.sort all the dges based upon weight
        sort(edgelist.begin(), edgelist.end());

     // Initialize a DSU - disjoint set union
     DSU s(v);

        int ans=0;
        for(auto edge : edgelist)
        // for loop over all the dges
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // we need to see if both edges belong to different
            // compomenets
            // we need to take that edge and unite it in MST
            // if it does not form a cycle

        // take that edge in MST if it doesnt form a cycle
            if(s.find(x)!=s.find(y))
            {
                s.unite(x,y);
                ans +=w;
            }

        }
        return ans;

    }
};
int main()
{
    // Graph g(4);
    // g.addEdge(0,1,1);
    // g.addEdge(1,3,3);
    // g.addEdge(3,2,4);
    // g.addEdge(2,0,2);
    // g.addEdge(0,3,2);
    // g.addEdge(1,2,2);

    int n, m;
    cin >> n>>m;

    Graph g(n);
    for(int i=0; i<m; i++)
    {
        int x,y,w;
        cin >> x >> y >> w;
        g.addEdge(x-1,y-1, w);
        // making index 0 base by substracting -1
    }


    cout << g.kruskal_mst() << endl;

    return 0;
}
//g++ sample.cpp -std=c++11

// input 
// 4 5
// 1 2 10
// 2 3 15
// 1 3 5
// 4 2 2
// 4 3 40

