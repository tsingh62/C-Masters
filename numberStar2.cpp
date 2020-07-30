#include<iostream>
using namespace std;

int main()
{
    int i,j,n;
    cin >> n;
	if (n == 0) {      
        return 0;      
    }                   
                       
    if (n < 0) {        
        n = n * (-1);  
    }      
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if (j<=i)
                {
                    cout << j;
                }
                else
                {
                    cout <<"*";
                }
                
            }
          cout << endl;  
        }
    return 0;
}