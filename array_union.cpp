#include<iostream>
using namespace std;
#include<vector>
/*
    - Union of two arrays 
    - arr1[1,3,4,5,7];
    - arr2[2,3,5,6];

    ans - {1,2,3,4,5,6,7};

    - Intersection is the common between the two arrays 
    - arr1[]{1,3,4,5,7};
    - arr2[]{2,3,5,6};

    ans - {3,5};

*/

int main()
{
    int arr1[]={1,3,4,5,7};
    int arr2[]= {2,3,5,6};
    int n = sizeof(arr1)/sizeof(int);
    int m = sizeof(arr2)/sizeof(int);
   
    vector<int> ans;

    for(int i=0; i<n; i++)
    {
        ans.push_back(arr1[i]);
    }

   
    for(int i=0; i<m; i++)
    {
        bool duplicate = false;
        for(int j=0; j<ans.size(); j++)
        {
            if(arr2[i]==ans[j])
            {
                duplicate = true;
            }
        }
        if(!duplicate)
        {
            ans.push_back(arr2[i]);
        }
    }

    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}