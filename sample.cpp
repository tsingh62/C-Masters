#include<iostream>
using namespace std;
#include<vector>
int main()
{
    int arr1[]={1,3,4,5,7};
    int arr2[]={2,3,5,6};
    int n = sizeof(arr1)/sizeof(int);
    int m = sizeof(arr2)/sizeof(int);

    vector<int> ans;

    bool duplicate = false;
    int j = 0;
    for(int i=0; i<n; i++)
    {
        if(arr1[i]==arr2[j])
        {
            duplicate = true;
        }
        if(duplicate)
        {
            ans.push_back(arr1[i]);
        }
        j++;
    }
    for(int i=0; i<n; i++)
    {
        cout << ans[i] << " ";
    }

}