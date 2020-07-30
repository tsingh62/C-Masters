#include<iostream>
using namespace std;

int main()
{
    int i,j,n=5;

    for(i=1; i<=n; i++)
    {
        for(j=n-i+1; j<=n-1; j++)
        {
            cout << j;
        }
    
    // no of 5
    for(int k=1; k<=n-i+1; k++)
    {
        cout << "5";
    }
    cout << endl;
    }

}