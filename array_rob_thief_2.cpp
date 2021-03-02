/*
 You are a professional robber planning to rob 
 houses along a street. Each house has a certain amount
 of money stashed. All houses at this place are arranged
 in a circle.
 That means the 1st house is the neighbour of the last 
 one. Meanwhile, adjacent houses have security system
 connected and it will automatically contact the police
 if two adjcent houses were broken into on the same night.

 Given a list of non- negative integers representing the 
 amount of money of each house, determine the max amount 
 money you can rob tonight without alearting the police.

		circular houses
					1,2,3,4,5,6,7
		 7  1
		6	 2
		5	 3
		   4

*/
#include<iostream>
using namespace std;
#include<vector>
class Solution
{
	public:
	int solve(vector<int> nums)
	{
		int n = nums.size();
		if(n==0)
			return 0; // when there are no houses
		vector<int> ans(n);
		if(n >= 1)
			ans[0] = nums[0]; // when there is only one house
		if(n >= 2)
			ans[1] = max(nums[0], nums[1]); // when there are 2 houses
		for(int i=2; i<n; i++)
			ans[i] = max(ans[i-1],ans[i-2]+nums[i]);
			// 2, 7, 9, 3, 1
			// when u are at 9 you have two options
			// for n-1 the max can be till 7.
			// or for n-2 = it will be
			// 2 and 9 
		return ans[n-1];
	}
	int rob(vector<int>&nums)
	{
		if(nums.size()==0)
			return 0;
		if(nums.size()==1)
			return nums[0]; // 1st value
		return max(solve(vector<int>(nums.begin(), nums.end()-1)),solve(vector<int>(nums.begin()+1,nums.end())));
		// logic used is 				
		// 1st option is 1,2,3,4,5,6, | -> 7 (excluding the last value)
		//  2nd option is  1 <-| 2,3,4,5,6,7 (excluding the 1st option since)
		// it is a circular array
	}
};

int main()
{
 	vector<int> nums = {1,2,3,1}; // output 4
	Solution s;
	cout << s.rob(nums) << endl;
}