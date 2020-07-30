#include<iostream>
#include<cstring>
using namespace std;

// largest string   

int main()
{
    // taking input
    int n;
    cin>> n;

    // creating the largest array
    char a[1000];
    // another array
    char largest[1000];
    int len=0;
    int larget_len=0;
    cin.get(); // to remove null in the loop below
    // when we type from getline
    for(int i=0; i<n; i++)
    {
        cin.getline(a,1000);
       // cout << a << endl;
       len = strlen(a);
       if(len>larget_len)
       {
           larget_len=len;
           strcpy(largest,a);
       }
    }
    cout << largest << " and " << larget_len << endl;
    return 0;
}
