#include<iostream>
using namespace std;

// palindromic substring
class Solution
{
    public:
    int countSubstrings(string str)
    {
        int count = 0;

        for(int i=0; i<str.length(); i++)
        {
            //odd length
            int left = i;
            int right = i;
            while(left>=0 && right <str.length())
            {
                if(str[left]==str[right])
                {
                    count++;
                    left--;
                    right++;
                }
                else
                {
                    break;
                }
                
            }
            // even length
            left = i;
            right = i+1;
            while(str[left] >=0 && str[right]<str.length())
            {
                if(str[left]==str[right])
                {
                    count++;
                    left--;
                    right++;
                }
                else
                {
                    break;
                }
                
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    string str;
    cin >>str;
    cout << s.countSubstrings(str) << endl;
    return 0;
}