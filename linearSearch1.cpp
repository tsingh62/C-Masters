
#include <iostream>
using namespace std;

int main()
{
    int a[1000];
    int n, key=9;
    int pos;


    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    // cout << "Enter the key value";
    // cin >> key;

    for(int i=0; i<=n-1; i++)
    {
        pos++;
        if(a[i]==key)
        {

            cout << a[i] << endl;
            cout << pos;
            break;
        }
        if(i==n)
        {
            cout << key ;
        }
    }
    cout << endl;
    return 0;
}