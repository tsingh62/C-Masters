#include<iostream>
using namespace std;
#include<vector>
#include<set>
// longest consecutive subsequence
int longestConSeq(vector<int> &nums)
{
    set<int> hashSet;

    for(int val : nums)
    {
        hashSet.insert(val);
    }

    int longestStreak = 0;
    for(int num : nums)
    {
        if(!hashSet.count(num-1))
        {
            int currNum = num;
            int currStreak = 1;

            while(hashSet.count(currNum + 1))
            {// check in the hash set if the 
            // next number exists or not
                currNum += 1;
                currStreak +=1;
            }
            longestStreak = max(longestStreak, currStreak);
        }
    }
    return longestStreak;
}
int main()
{
    // vector<int> nums = {1,9,3,10,4,20,2};
    vector<int> nums = {2,6,1,9,4,5,3};
    cout << longestConSeq(nums) << endl;
}