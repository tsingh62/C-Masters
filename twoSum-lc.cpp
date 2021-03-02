
// Solution link
// https://leetcode.com/problems/two-sum/discuss/401897/c-solution-with-explaination

#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
Target sum is 9 - 

store 2 with its index
2.0 in m
then take the difference 9-7 = 2
and then search 2 in map then the ans will 
be 0,1(index value) of the array 

*/
vector<int> v;
class Solution {
 public:
     vector<int> twoSum(vector<int>& nums, int target) 
     {
         map<int, int> m; // creating a map
        // vector<int> v;
          // vector to store integer
         int n = nums.size(); 

         for(int i=0; i<n; i++)
         {
             //  
             int diff = target - nums[i];
             // search for the no if its present 
             // in the map or not
             if(m.find(diff) != m.end())
             {
                 // if present then fetch
                 // that np from map and 
                 /// put the result in vector
                 auto p = m.find(diff);
                 v.push_back(p->second);
                 v.push_back((i));
             }
             m.insert(make_pair(nums[i],i));
             // if the no is not presnt in map 
             // we will be inserting the current no idx
             // in map
         }
         return v; // return resultant vector
     }
 };
 int main()
 {
     vector <int> nums = {2,7,11,15};
     int target = 9;
     Solution  s;
    // Solution vector<int> s;
    //  s.twoSum(nums, target);
 
    vector <int> x;
    x = s.twoSum(nums, target);
   //  cout << x.front() << x.back()<< endl;
    for(int val : x)
    {
        cout << val << " ";
    }
    cout << endl;
}



 /*
 #include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
vector<int> func(vector<int>arr, int target)
{
	vector<int> ans;
	unordered_map<int, int> mpp;
	for(int i=0; i<arr.size(); i++)
	{
		if(mpp.find(target - arr[i])!=mpp.end())
		{
			ans.push_back(mpp[target-arr[i]]);
			ans.push_back(i);
			return ans;
		}
		mpp[arr[i]] = i;
	}
	return ans;
}
int main()
{
	 vector <int> arr = {2,7,11,15};
     int target = 9;

	 for(int i=0; i<arr.size(); i++)
	 {
		 cout << arr[i] << " "; 
	 }
	 cout << endl;
}
 */