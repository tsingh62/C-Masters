#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[1005];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int target;
    cin >> target;

    for(int i=0; i<n; i++)
    {
        int l = i+1;
        int r = n-1;

        while(l < r)
        {
            if(arr[i]+arr[l]+arr[r]==target)
            {
                cout << arr[i] << " and " << arr[l] << " and " << arr[r] << endl;
                l++;
                r--;
            }
            else if(arr[i] + arr[l] + arr[r] < target)
            {
                l++;
            }
            else
            {
                r--;
            }
            
        }
    }
    return 0;
}