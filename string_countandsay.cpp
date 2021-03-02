#include<iostream>
using namespace std;
#include<string>
/*
count as 1
input 1;
1 -
11 - read from previous line 1 is used 1
21 - read from previous line 2 times 1
1211 - read from previous line two is one time so (12 and then 1 is used 1)
111221 - read from previos line 1 is used once
        so 11 then 2 is used once so 21 and 1 is used 2wice so 21
        so 11 12 21
312211 - read from previous line 1 is used 3 times -
        2 us used 2 times and then 1 is used once.
*/
class Solution
{
    public:
    string countAndSay(int n)
    {
        string s = "1"; 
        while(n--)
        {
            string newStr;
            int i = 0;
            while(i < s.size())
            {
                int count = 1;
                while(i + 1 < s.size() && s[i] == s[i+1])
                {
                    i++;
                    count++;
                }
                newStr += to_string(count) + s[i];
                i++;
            }
            s = newStr;
        }
        return s;
    }
};

int main()
{
 Solution s;
 cout << s.countAndSay(5) << endl; 
}