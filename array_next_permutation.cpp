#include<iostream>
using namespace std;
#include<vector>
class Solution
{
    public:
    void nextPermutation(vector<int> &arr)
    {
        int n = arr.size(), k , l;
    // iterate from 2nd last index and find the break point
        for(k = n-2; k>=0; k--)
        {
            if(arr[k] < arr[k+1])
            {
                break;
            }
        }
        if(k < 0)
        {   //if there is no break point simply reverse it
            reverse(arr.begin(), arr.end());
        }
        else
        {   // if you find a break point 
            for(l = n-1; l>k; l--)
            {
                if(arr[l]>arr[k])
                {
                    break;
                }
            }
            swap(arr[k], arr[l]);
            reverse(arr.begin()+k+1, arr.end());
        }
        
    }
};
int main()
{
    vector<int> arr ={1,1,5};
    Solution s;
    s.nextPermutation(arr);
    for(int i=0; i<arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}