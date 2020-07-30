#include <iostream>
using namespace std;

int main()
{
    int row, sp, incVAl, decVal, n=5;

    for(row=1; row<=n; row++)
    {
        for(sp = 1; sp <= n-row; sp++)
        {
            cout <<" ";
        }
        for(incVAl=1; incVAl<=row; incVAl++)
        {
            cout << incVAl;
        }
        for(decVal=row-1; decVal>=1; decVal--)
        {
            cout << decVal;
        }
    cout << endl;
    }
}