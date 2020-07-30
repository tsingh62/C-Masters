#include<iostream>
using namespace std;

int main()
{
    int i,j,k,l,n;
    cin >> n;
    if(n==0)
    {
        return 0;
    }
    if(n<10)
    {
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j<=i)
                cout<<j<<"  ";
            else
                cout<<"   ";
        }
        for(k=n-1;k>i;k--)
        {
            cout<<"   ";
        }
        l=i; // starts from 1
            if(l==n)
            {
                l=l-1;
                while(l>0)
                {
                    cout<<l<<"  ";
                    l--;
                }
            }
            else if(l<n)
            {
                while(l>0)
                {
                    cout<<l<<"  ";
                    l--;
                }
        }
     cout<<endl;
    }
    }
return 0;
}