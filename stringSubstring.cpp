
#include<iostream>
using namespace std;


void subStrings(string str)
{
    int n = str.length();

    for(int i=0; i<n; i++)
    {
        int startindex = i;

        for(int len=1; len<=(n-i); len++)
        {
            cout << str.substr(startindex, len);
            cout << endl;
        }
        cout << endl;
    }
}
int main()
{
    subStrings("abcd");
    return 0;
}