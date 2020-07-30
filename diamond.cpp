
#include<iostream>
using namespace std;

int main()
{
    int n=3;
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout << " " ;
        }
        n--;
        for(int k=1; k<=i; k++)
        {
            cout <<"*" <<  " ";
        }
    cout << endl;
    }
    int m=1;
    for(int i=1; i<=3; i++)
    {
        
        for(int j=1; j<=m; j++)
        {
            cout << " " ;
        }
        m++;
        for(int k=3; k>=i; k--)
        {
            cout <<"*" << " ";
        }
    cout << endl;
    }

}