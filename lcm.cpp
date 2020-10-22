#include <iostream>
using namespace std;


void func(int n1, int n2, int lcm)
{
   if(n1 < 0 && n1 > 1000000000)
   {
       return;
   }
   if(n2 < 0 && n2 > 1000000000)
   {
       return;
   }
   if(n1>n2)
   lcm = n1;
   else
   lcm = n2;
   while(1) 
   {
      if( lcm%n1==0 && lcm%n2==0 ) 
      {
         cout<<" The LCM of "<<n1<<" and "<<n2<<" is "<<lcm << endl;
         break;
      }
      lcm++;
   }
}
int main() 
{
   int n1;
   int n2;
   int lcm;
   cin >> n1;
   cin >> n2;
   func(n1,n2,lcm);

  
   return 0;
}