#include<iostream>
using namespace std;
#include<vector>

// longest path
// 1



/// 2
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        //find the longest path in the tree
        vector<vector<int>> lists(n);
        for(auto p : edges) {
            lists[p.first].push_back(p.second);
            lists[p.second].push_back(p.first);
        }
        
        int len;
        vector<int> prev(n, 0);
        int f1 = findFarthestLeaf(lists, 0, len, prev);
        int f2 = findFarthestLeaf(lists, f1, len, prev);

        //find the mid
        for(int i = 0; i < (len - 1) / 2; ++i) {
            f2 = prev[f2];
        }
        if(len % 2) return vector<int>{f2};
        else return vector<int>{f2, prev[f2]};
    }
    
    int findFarthestLeaf(vector<vector<int>>& lists, int id, int& len, vector<int>& prev) {
        int n = lists.size();
        
        vector<bool> visited(n, 0);
        visited[id] = true;
        prev[id] = id;
        
        queue<int> q;
        q.push(id);
              
        len = 0;
        int leaf;
        while( !q.empty() ) {
            len++;
            int size = q.size();
            while(size-- > 0) {
                int f = q.front();
                q.pop();
                leaf = f;
                for (int i : lists[f]) {
                    if (!visited[i]) {
                        visited[i] = true;
                        q.push(i);
                        prev[i] = f;
                    }
                }
            }
        }
    
        return leaf;
    }
};