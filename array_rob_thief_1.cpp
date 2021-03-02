#include<iostream>
using namespace std;
#include<vector>
/*
MAXIMIZE SUM SUCH THAT NO TW0 ELEMENTS ARE ADJACENT
____________________________________________________

Stickler the thief wants to loot money 
from a society having n houses in a single line. 
He is a weird person and follows a certain 
rule when looting the houses. According to the rule, 
he will never loot two consecutive houses. 
At the same time, he wants to maximize 
the amount he loots. The thief knows which 
house has what amount of money but is unable 
to come up with an optimal looting strategy. 
He asks for your help to find the maximum money 
he can get if he strictly follows the rule. 
Each house has a[i] amount of money present in it.

Input:
The first line of input contains an 
integer T denoting the number of test cases. 
T testcases follow. Each test case contains 
an integer n which denotes the number of houses. 
Next line contains space separated numbers 
denoting the amount of money in each house.
*/
class Solution
{
	public:
	int rob(vector<int> &nums)
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
};

int main()
{
 	vector<int> nums = {5, 5, 10, 100, 10, 5}; // ans = 110
	Solution s;
	cout << s.rob(nums) << endl;
}