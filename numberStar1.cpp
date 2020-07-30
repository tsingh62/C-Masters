
#include<iostream>
using namespace std;

int main()
{
    // number star 1
    int i,j,k,n;
    cin >> n;

    for(i=1; i<=n; i++)
    {   
        int val =1; 
        for(j=n; j>=i; j--)
        {
            cout<<val << " ";
            val++;
        }
           
    for(k=1; k<=2*(i-1)-1; k++)
    {
        cout<< "* ";
    }
    cout << endl;
    }
}