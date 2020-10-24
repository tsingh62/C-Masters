#include<iostream>
using namespace std;

 #include<iostream>
 using namespace std;

class Solution
{
    public:
    int balancedStringSplit(string str)
    {
        int leftCount = 0;
        int rightCount = 0;

        int totalCount = 0;

        for(int i=0; i<str.length(); i++)
        {
             char ch = str[i];
             if(ch == 'L')
             {
                 leftCount++;
             }
             else
             {
                 rightCount++; 
             }
             
        
        if(leftCount==rightCount)
        {
            // incremnet total count by 1
            totalCount+=1;
            // leftCount=0;
            // rightCount=0;
        }
        }
        return totalCount;
    }
};

 int main()
 {
     Solution s;
     string str;
     cin >> str;
     cout <<s.balancedStringSplit(str)<<endl;
     return 0;
 }