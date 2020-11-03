#include<iostream>
using namespace std;
#include<vector>


int main()
{
    // - Intersection is the common between the two arrays 
    // - arr1[]{1,3,4,5,7};
    // - arr2[]{2,3,5,6};

    // ans - {3,5};

    int arr1[]={1,3,4,5,7};
    int arr2[]={2,3,5,6};
    int n = sizeof(arr1)/sizeof(int);
    int m = sizeof(arr2)/sizeof(int);

    vector<int> ans;

    // for(int i=0; i<n; i++)
    // {
    //     ans.push_back(arr1[i]);
    // }

    for(int i=0; i<n; i++)
    {   bool duplicate = false;
        for(int j=0; j<m; j++)
        {
            if(arr1[i]==arr2[j])
            {
                duplicate = true;
            }
        }
        if(duplicate)
        {
            ans.push_back(arr1[i]);
        }
    }
    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

}