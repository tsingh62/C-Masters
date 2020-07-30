#include<iostream>
using namespace std;


int main()
{
    int i,j,k,l,n=4;

    for(i=1; i<=n; i++)
    {
        int val=1;
        for(j=n-i; j<=n-1; j++)
        {
         cout << val<<"    ";   
         val++;
        }
        // stars
        for(int k=1; k<=n-i; k++)
        {
            cout <<"*   ";
        }
        
        // stars
        for(int k=n-1; k>i; k--)
        {
            cout <<"*   ";
        }
        //correct till here 
        
        // new logic - derived 
        int val1=i;

        if(val1==n)
        {
            val1=val1-1;
            while(val1>0)
            {
                cout << val1<<"    ";
                val1--;
            }
        }
        else if(val1<n)
            {
                while(val1>0)
                {
                    cout << val1<<"    ";
                    val1--;
                }
            }
        cout << endl;  
        }
    return 0;  
}
    

