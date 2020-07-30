#include<iostream>
using namespace std;
int main() 
{
	int n,i,j;
    int val = 1;
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
            
            if (i==j || j==1)
            {

                val =i-1;
                
                if(val==0)
                {
                    val=1;
                }  
                cout << val;     
            }
            else
            {
                val = 0;
                cout << val;
            }
            
        }
    cout << endl;
    }
    }
	return 0;
}