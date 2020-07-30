#include<iostream>
using namespace std;

int main()
{
    int i,j,n;
    cin >> n;

    if(n==0)
    {
        return 0;
    }
    if(n<100)
    {
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            if(j==i || j==1) 
            {
                cout << i << "  ";
            }
            else
            {
                cout << "0" << "   ";
            }
            
        }
     cout << endl;
    }
    }
}