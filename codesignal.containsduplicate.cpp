#include<iostream>
using namespace std;
#include<vector>

// 1

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        map<int, bool> set;
        
        for(int index = 0;index < size;index++){
            if(set.find(nums[index]) != set.end()){
                return true;
            }
            set[nums[index]] = true;
        }
        
        return false;
    }
};

////////////
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int index = 1;index < size;index++){
            if(nums[index - 1] == nums[index])
                return true;
        }
        
        return false;
    }
};
///////////
bool containsDuplicate(int* nums, int numsSize) {
    int sorted, elem;
    
    for(sorted = 0;sorted < numsSize;sorted++){
        for(elem = 0;elem < numsSize - sorted - 1;elem++){
            if(nums[elem] > nums[elem + 1]){
                int tmp = nums[elem];
                nums[elem] = nums[elem + 1];
                nums[elem + 1] = tmp;
            }else if(nums[elem] == nums[elem + 1]){
                return true;
            }
        }
    }
    
    return false;
}

// 2

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty() && k==0)return false;  //base case
//mp map element with its position or index number as in given nums vector
        vector<pair<int, int>> mp; 

        for(int i=0;i<nums.size();i++){
            mp.push_back({nums[i],i}); //maps element and its index in nums
        }
// sorting the mp vector will bring the duplicates next to each other
        sort(mp.begin(),mp.end()); 
        bool flag=false; //flag tells if condition is met or not if yes true else false
//Now we check if adjacent element has same value and its indexes in original vector nums is less than equal to k or not if yes make flag true        
        for(int i=0;i<mp.size()-1;i++){
            if((mp[i].first==mp[i+1].first) &&((mp[i+1].second-mp[i].second)<=k))flag=true;
        }
        return flag;
    }
};


///////////////

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        int start = 0;
        int end = 0;
        
        while(end < nums.size()) {
            if(end - start > k) {
                start++;
            }            
            auto it = m.find(nums[end]);
            if(it != m.end() && it->second >= start) {
                return true;
            }            
            m[nums[end]] = end;
            end++;
        }        
        return false;
    }
};
//////

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++) {
             if(mp.count(nums[i]) && abs(mp[nums[i]]-i)<=k) { 
            /* 
             if the val prev. index in map - current index is atmost k 
             then return true else update the value to its new index as our answer will not get better from prev index. */
                 return true;
             }else {
                 mp[nums[i]]=i;
             }
        }
        return false;
    }
};

// 3
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        set<int> ss(nums.begin(), nums.end());
        if( t == 0 && n == ss.size()) return false;
            
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < i+1+k; ++j){
                if(j >= n) break;
                if(abs((long long)nums[i] - nums[j]) <= t) return true;
            }
        }
        return false;
    }
};