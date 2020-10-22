#include<iostream>
using namespace std;
#include<vector>


int main()
// compare two arrays
{
    int a[]={1,2,3,4,5};
    int b[]={1,2,3,4,5};
    int n = sizeof(a)/sizeof(int);
    int m = sizeof(a)/sizeof(int);
    int ans;
    if(n > m)
    {
        ans = n;
    }
    else
    {
        ans = m;
    }
    
    int compare =1;

    for(int i=0; i < ans && compare; i++)
        if(a[i]!=b[i]) compare =0;

    if(compare)
        cout << "The array a and b are equal" << endl;
    else
        cout << "The array a and b are not equal" << endl;
    
    return 0;
}