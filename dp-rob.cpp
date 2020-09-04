

#include<iostream>
#include<vector>
using namespace std;

class solution
{
	public:
	
	int rob(vector<int> &nums)
	{
		int n = nums.size();
	//	vector <int> dp(n+1, -1);
		vector <int> dp(n+2, -1);
		return helper(0, nums, dp);
	}
	int helper(int si, vector <int> &nums, vector <int> &dp)
	{
		// Base Case
		 // this will be out of range
		if(si > nums.size())
		{
			return 0;
		}
		if(dp[si]!=-1)
		{
			return dp[si];
		}
		// Recursive Case
		// if you consider the 1st array value
            // nums[0]
            // sub-problem
		int include = helper(si+2, nums, dp)+nums[si];
				// including the value nums[si] as well
		
		// if you skip the 1st value
            // and start from the 2nd array value
		int skip = helper(si+1, nums, dp);

		int result = max(include, skip);
		
		dp[si]=result;
		
		return result;
	}

};

int main()
{
	vector <int> nums = {2,7,9,3,1};
	solution s;
	s.rob(nums);
	cout << s.rob(nums) << endl;
	
	return 0;
}
//g++ sample.cpp -std=c++11