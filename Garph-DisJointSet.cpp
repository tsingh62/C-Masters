
#include<iostream>
#include<vector>
#include<queue>
using namespace std;



struct dsu
{
    vector<int> par, sz;
    // initialize
    int total_comp;

    void init(int n)
    {
        par.resize(n);
        sz.resize(n);
        for(int i=0; i<n;i++) par[i]=i;
        for(int i=0; i<n;i++) sz[i]=1;
        // 1 as in 
        total_comp =n;
    }
    int get_superparent(int x)
    {
        if(x==par[x])
        {
            return x;
        }
        else
        {
            return par[x]=get_superparent(par[x]);
        }
    }
    void uNion(int x, int y)
    {
        int spuer_parent_x = get_superparent(x);
        int spuer_parent_y = get_superparent(y);
        if(spuer_parent_x != spuer_parent_y)
        {
            par[spuer_parent_x]=spuer_parent_y;
            sz[spuer_parent_y]+= sz[spuer_parent_x];
            sz[spuer_parent_x]=0;
            total_comp--;
            // when two compnents are merged(union)
            // the total no of components are reduced by 1
        }
    }
} G;
void solve()
{
    int i, j, k, n, m, ans=0, cnt=0, sum=0;
    cin >> n >> m;
    G.init(n);
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin >> x >> y;
        G.uNion(x,y);
        
    }
    // all elements  are in theri connected components
    for(int i=0; i<n; i++)
    {
// i is considered as x
        int super_parent_i = G.get_superparent(i);
        ans += n - G.sz[super_parent_i];
    }
    cout << ans/2;
    // since there are 12 pairs and the values are 
    // repeated 2 times so we need to divide the ans/2
}

int32_t main()
{

//   lets_do_it();
    // int t, cin >> t; while(t--)
    solve();
    return 0;
}


//g++ sample.cpp -std=c++11

// input
// 5 3
// 0 1
// 2 3
// 0 4


