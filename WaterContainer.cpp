

#include<iostream>
using namespace std;
    
    
    int Area(int height[], int n)
    {
        
        int left =0;
        int right = n-1;
        int maxArea =0;

        while(left<right)
        {
            int minHeight = min(height[left], height[right]);
            int gap = right-left;
            int currArea = minHeight*gap;

            if(currArea > maxArea)
            {
                maxArea = currArea;
            }
            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
            
        }
        return maxArea;
    }
    
    int main()
    {
        int height [] = {1,8,6,2,5,4,8,3,7};
        int n = sizeof(height)/sizeof(int);

        cout << Area(height, n) << endl;
        return 0;
    }

/*
class Solution
{
    public:
    int func(vector<int> arr)
    {
        int n = arr.size();
        return helper(arr,n);
    }
    int helper(vector<int> arr, int n)
    {
        int left=0;
        int right=n-1;
        int maxArea =0;
        while(left< right)
        {
            int minht = min(arr[left], arr[right]);
            int gap = right-left;
            int curArea = minht*gap;

            if(curArea > maxArea)
            {
                maxArea = curArea;
            }

            if(arr[left]<arr[right])
            {
                left++;
            }
            else
            {
                right--;
            }
            
        }
        return maxArea;
    }
};
int main()
{
    vector<int> arr={1,8,6,2,5,4,8,3,7};
    Solution s;
    cout << s.func(arr) << endl;
    return 0;
}
*/