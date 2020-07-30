
#include<iostream>
using namespace std;

int main()
{
    int i,j,k,n;
    cin >> n;
    if(n==0)
    {
        return 0;
    }
    if(n<=20)
    {
    for(i=1; i<=n; i++)
    {
        int val=n-1;
        for(j=4; j>=i; j--)
        {
            
            cout << " ";
        }
        for(k=1; k<=n; k++)
        {
            
            if(k==n|| k==1 || i==1 || i==n)
            {
                cout << "*";
            }  
            else
            {
                cout << " ";
            }
            
        }

      
    cout << endl;
    }
    }
    return 0;
}