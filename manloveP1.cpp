#include<iostream>
using namespace std;

int main()
{
    int i, j, n;
    cin >> n;
    if(n==0)
    {
        return 0;
    }
    if(n<=1000)
    {
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            if(i%2!=0 || j==1 || j==i)
            {
                cout << "1";
            }
            else
            {
                cout <<"0";
            }
            
        }
     cout << endl;   
    }
    }
    return 0;
}