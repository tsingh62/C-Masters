#include<iostream>
using namespace std;
#include<vector>


 // combi 1
class Solution {
public:
    vector<int> candidates2;
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> combine;
        candidates2=candidates;
        combination(target,0, combine);
        return result;
    }
    
    void combination(int target, int start,vector<int> &combine){
        if(target==0){
            result.push_back(combine);
            return;
        }
        for(int i=start;i<candidates2.size();i++){
            if(target<candidates2[i])break;
            combine.push_back(candidates2[i]);
            combination(target-candidates2[i],i,combine);
            combine.pop_back();
        }
    }
};


// combi 2


#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
    
    vvi ans;
    vi curr;
    int n;
    
    void fillNext(int idx, vi& candidates, int target) {
        
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        
        if(idx == n) return;
        
        for(int i = idx ; i < n ; i++) {
            if(i == idx or candidates[i] != candidates[i-1]) {
                if(candidates[i] <= target) {
                    curr.push_back(candidates[i]);
                    fillNext(i+1,candidates,target-candidates[i]);
                    curr.pop_back();
                }
            }
        }
    }
    
    vvi combinationSum2(vi& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(),candidates.end());
        fillNext(0,candidates,target);
        return ans;
    }
};