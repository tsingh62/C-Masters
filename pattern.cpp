#include <iostream>
using namespace std;

int main()
{
 
 int i, j, r=5;

 for (i=1; i<=r; i++)
 {
     for(j=1; j<=r; j++)
     {
         if(i+j == 4 || i+j ==8 || i==j+(r/2) || j==i+(r/2)) 
         {
             cout << "*";
         
            if(i==j) 
            {
                cout << " ";
            }
         }
        else
        {
            cout << " ";
        }
        
 
    }  
    cout << endl;
 }
}

    
    