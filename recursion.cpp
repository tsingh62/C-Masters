
#include<iostream>
using namespace std;

int power(int n, int p)
{
    if (p==0)
    {
        return 1;
    }
    
   int subprob = power(n, p-1);
   int ans = n*subprob;
   return ans;
  

    
}

// find the number which is not in pair
int main()
{
    cout << power(2,3) << endl;
    return 0;

}
