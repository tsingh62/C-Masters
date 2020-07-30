
#include<iostream>
using namespace std;

int main()
{
    int n;
    int last = 1000;
    bool prime;
    cin >> n;

    if(n==0)
    {
        return 0;
    }
 
   
    if(n<=last)
    {
        for(int i=2; i<=n; i++)
        {
            prime = true;
            for(int j=2; j<=i/2; j++)
            {
                if(i%j==0)
                {
                    prime=false;
                    break;
                }
            }
            if(prime)
            {
                cout << i << " ";
            }
           
        }
    }   

    cout << endl;

    return 0;
}