
#include<iostream>
using namespace std;

// incredible hulk
int hulk(int n)
{
    int count =0;
    while(n>0)
    {
        int val = n&1;
        {
            if (val==1)
            {
                count++;
            }
        n=n>>1;
        }

    }
    return count;
}
int main()
{
   cout << hulk(13) << endl;
   return 0;
}