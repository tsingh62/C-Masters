#include<iostream>
using namespace std;

class Solution
{
    public:
    void func(int arr[], int n)
    {
        int low = 0;
        int mid = 0;
        int hi = n-1;

        while (mid <= hi)
        {
            switch(arr[mid])
            {
                //if the element is 0
                case 0: 
                // swap low and mid 
                // and increases low and mid by 1
                swap(arr[low++], arr[mid++]);

                // if element is 1
                case 1:
                mid++;
                break;

                case 2:
                // swap mid and hi
                // 
                swap(arr[mid], arr[hi--]);
                break;
            }
        }
        
        
    }
};
int main()
{
    int arr[] = {0, 2, 1, 2, 0};
    int n = sizeof(arr)/sizeof(int);
    Solution s;
    s.func(arr, n);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


