#include<iostream>
using namespace std;

void func(int num)
{
   // sum of digits
      
		
		int rev = 0;
		
		while(num>0)
		{
			rev = rev*10;
			rev = rev + num%10;
			num = num/10;
		}
	cout << rev << endl;
		
   
}
int main()
{

   int n;
   cin >> n;
   func(n);
   return 0;
}