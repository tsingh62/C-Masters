#include<iostream>
using namespace std;

int power (int base, int n)
{
    int result =1;

    for(int i=1; i<=n; i++)
    {
        result = result * base;
    }
    return result;
}

int main()
{
    int n;
    int base;
    cout << " Enter base value" << endl;
    cin >> base;

    cout << "Enter power value " << endl; 
    cin >> n;

    cout << power(base, n) << endl;
    return 0;


}