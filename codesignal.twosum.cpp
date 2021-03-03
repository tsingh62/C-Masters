#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

class Solution
{
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // vector<int> result;
        // for(auto it1 = nums.begin(); it!=nums.end(); ++it1)
        // {
        //     auto it2 = find(it1+1, nums.end(), target - *it1);
        //     if(it2 != nums.end()){
        //         result.push_back(it1 - nums.begin());
        //         result.push_back(it2 - nums.begin());
        //         break; 
        //     }
        // }
        // return result;


        unordered_map<int, int> _map
        for(int i=0; i< nums.size(); ++i){
            int num = nums[i];
            int complement = target - num;
            auto it = _map.find(complement);
            if(it != _map.end()){
                return {it->second, i};
            }
            _map[num] = i;
        }
        return {};
    }
}