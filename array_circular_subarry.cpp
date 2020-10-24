#include<iostream>
using namespace std;
#include<vector>

// maximum sum circular sunarray sum
class Solution
{
    public:
    int maxSubarrySumCircular(vector<int>&arr)
    {
        int n = arr.size();
        int currSum = arr[0];
        int maxSum = arr[0];
        
        int currMinSum = arr[0];
        int minSum = arr[0];

        int total = arr[0];

        for(int i = 1; i<n; i++)
        {
            //kadanes algo for max sum
            currSum = max(currSum + arr[i], arr[i]);
            maxSum = max(maxSum, currSum);

            // kadannes also for min sum 
            currMinSum = min(currMinSum+arr[i], arr[i]);
            minSum = min(minSum, currMinSum); 
        }
        if(maxSum > (total - minSum))
        {
            return maxSum;
        }
        else
        {
            return total - minSum;
        }
        
    }
};
int main()
{
    Solution s;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << s.maxSubarrySumCircular(arr) << endl;
    return 0;
}