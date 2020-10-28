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


/*
#include<iostream>
int main() {
    int num1,num2;
    cin >> num1>>num2;

    if(num1>num2){
        int temp = num2;
        num2=num1;
        num1=temp;
    }

    int lcm=num2;
    while(lcm>0){
        if(lcm%num2==0 && lcm%num1==0){
            break;
        }
        lcm++;
    }
    cout << lcm << std::endl;
    return 0;
}
*/