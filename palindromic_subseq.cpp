#include<iostream>
using namespace std;
// longest palindromic - count
// palindromic substring - for substring
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
          //  while(str[left] >=0 && str[right]<str.length())
            while(left >= 0 && right < str.length())
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
// longest palindrome in a string - to return largest string in a substr
/*
#include<iostream>
using namespace std;

class Solution
{
    public:
    string longestPalindrome(string s)
    {
        if(s.length()<=1)
        {
            return s;
        }
        int maxLen = 1;
        int n = s.length();
        int start = 0;
        int end = 0;

        for(int i=0; i<n-1; i++)
        {
            //for odd
            int left = i;
            int right = i;
            while(left>=0 && right<n)
            {
                if(s[left]==s[right])
                {
                    left--;
                    right++;
                }
                else
                {
                    break;
                }
            }
            int len = right - left - 1;
            if(len > maxLen)
            {
                maxLen = len;
                start = left + 1;
                end = right - 1;
            }
            left = i;
            right = i+1;
           while(left>=0 && right<n)
            {
                if(s[left]==s[right])
                {
                    left--;
                    right++;
                }
                else
                {
                    break;
                }
            }
            len = right - left - 1;
            if(len > maxLen)
            {
                maxLen = len;
                start = left + 1;
                end = right - 1;
            }
        }
        return s.substr(start,  maxLen);
    }
   
};

int main()
{
    string s;
    cin >> s;
    Solution s1;
    cout << s1.longestPalindrome(s) << endl;

}
*/