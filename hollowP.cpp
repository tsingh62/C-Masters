#include<iostream>
using namespace std;

int main()
{
    int i,j,k,z,n=5;
    
    for(i=1; i<=n; i++)
    {
        for(j=n; j>i-1; j--)
        {
            cout << "*";
        }
        for(k=1; k<=(2*i)-2; k++)
        {
            cout << " ";
        }
        for(z=n; z>i-1; z--)
        {
            cout << "*";
        }

    cout << endl;
    }
    // 2nd half
    for(i=n-1; i>=1; i--)
    {
          for(j=n; j>i-1; j--)
        {
            cout << "*";
        }
        for(k=1; k<=(2*i)-2; k++)
        {
           cout << " ";

        }
        for(z=n; z>i-1; z--)
        {
            cout << "*";
        }
    cout << endl;
    }
}