#include<iostream>
using namespace std;


int main()
{
    int n;
    int row, sp, inc, dec;
    int last=10;
    int val=1;

    cin >>n;
    if(n==0)
    {
        return 0;
    }
    if(n<last)
    {
        for(row=1; row<=n; row++)
        {
            

            for(sp=1; sp<=n-row; sp++)
            {
                cout <<  "   ";
                
            }
            for(inc=1; inc<=row; inc=inc-1)
            {   
                ++val;
                cout << val << "  ";    
                    
            }
            for(dec=row-1; dec>=1; dec--)
            {
                cout << dec<< "  ";
            }
        cout << endl;
        }
    }
    return 0;
}