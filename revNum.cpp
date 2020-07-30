#include<iostream>
using namespace std;

int main()
{
    long long num;
    long long last = 1000000000;
    int sum = 0;
    int rem;
    cin >> num;

    if(num==0)
    {
        return 0;
    }
    if(num<=last)
    {
        while(num>0)
        {
            rem = num%10;
            sum = (sum*10)+rem;
            num = num/10;
            
        }
        cout << sum;
    }
    cout << endl;

    return 0;
}