#include<iostream>
using namespace std;

void func(int num)
{
   int rev = 0;
   
   while(num > 0)
   {
     cout << (rev + num%10);
     num = num/10;
   }
   
   
}
int main()
{

   int n;
   cin >> n;
   func(n);
   return 0;
}