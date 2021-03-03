#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

class  solution{

    public:
    vector<int> productExceptSelf(vector<int>&nums)
    {
        int n = nums.size();
        // vector<int> L(n, 1);
        //  vector<int> R(n, 1);
         vector<int> result(n, 1);


         for(int i=1; i<n; ++i)
            result[i] = result[i-1] * nums[i-1];
        
        int right_prod = nums[n-1];
        for(int i = n-2; i>=0; --1){
            result[i] *= right_prod;
            right_prod *= nums[i];
        }
           
        return result;

    }
}