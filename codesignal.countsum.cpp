#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

// count sum of range - best 

class Solution {
    class BIT{
        public:
        vector<long> sum;
        BIT(int n) { sum.resize(n); }
        void update(int i, long val){
            while(i < sum.size()){
                sum[i] += val;
                i += i & (-i);
            }
        }
        long query(int i){
            long res = 0;
            while(i > 0){
                res += sum[i];
                i -= i & (-i);
            }
            return res;
        }
    };
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.empty()) return 0;
        vector<long> sums(nums.size(), 0);
        sums[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) sums[i] = sums[i-1] + nums[i];
        set<long> sorted(begin(sums), end(sums));
        sorted.insert(0); //for range starting from 0
        unordered_map<long, int> mp;
        int rank = 1;
        for(auto sum: sorted) mp[sum] = rank++;
        BIT bit(rank);
        bit.update(mp[0], 1); //for range starting from 0
        int res = 0;
        for(auto sum: sums){
            //find all prefix-sum "X" such that sum - X >= lower && sum - X <= upper
            //=> X <= sum - lower && X >= sum - upper
            auto it = sorted.upper_bound(sum - lower);
            if(it != sorted.begin()){
                it--;
                int u = bit.query(mp[*it]); //logN
                auto it2 = sorted.lower_bound(sum - upper); //logN
                if(it2 != sorted.end()){
                    int l = bit.query(mp[*it2]-1); //logN
                    res += u - l;
                }
            }
            bit.update(mp[sum], 1);
        }
        return res;
    }
};

////




// sum range 2 
 
// Important header files   
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
#include <iostream>  
using namespace __gnu_pbds;  
using namespace std;  
typedef tree<long, null_type, less_equal<long>, rb_tree_tag,  
            tree_order_statistics_node_update>  
    ordered_set; 

class Solution {
public:
    int countRangeSum(vector<int>& nums, int l, int h) {
        int count = 0;
        long sum = 0;
        ordered_set sumSet;
        sumSet.insert(0);
        
        for (int num : nums) {
            sum += num;
            int a = sumSet.order_of_key(sum - h),
                b = sumSet.order_of_key(sum - l + 1);
            count += max(0, b - a);
            sumSet.insert(sum);
        }
        
        return count;
    }
};