#include<iostream>
using namespace std;

int main()
{
    int i,j,k,n=5;

    for(i=1; i<=n; i++)
    {
    
        for(j=1; j<=n; j++)
        {
            
            // cout << ".";
             
             if(i%2==0 || j%2==0)
             {
            
                 cout <<"-";
             }
             else
             {
                 cout<<" ";
             }
             
             
            
        }
        
        
    cout << endl;
    }
}