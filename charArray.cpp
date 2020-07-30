
#include<iostream>
using namespace std;


int main()
{
   int b[] = {1,2,3};
   cout << b << endl; // address

   char c[] = {'a','b','c','\0'};
   cout << c << endl; // contents

   // we do not need a loop for char array input 
   // unlike we do it for int values 
   // when we use cin 

    //null is automatically in a string 
   char s[10];
   cin>>s; // hello
   cout << s; // hello
   cout << endl;
}