#include<iostream>
using namespace std;
// print sub-strings

void subArray(string str)
{   
    int n= str.length();
    for(int i=0; i<n; i++)
    {
        int startindex=i;
        for(int j=1; j<=n-i; j++)
        {
            cout << str.substr(startindex, j) << endl;
            // for(int k=i; k<=j; k++)
            // {
            //     cout << str[k] << "" ;
            // }
            
        }
        
    }
    cout << endl;
}
int main()
{
    string str = "abcd";
    subArray(str);
    return 0;
}