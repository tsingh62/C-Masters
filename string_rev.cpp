#include<iostream>
using namespace std;
#include<vector>
class Solution
{
    public:
    void reverseString(vector<char> s)
    {
        int left = 0;
        int right = s.size()-1;

        while(left < right)
        {
        //    swap(s[left], s[right]);
        //    left++;
        //    right--;
        char temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;

        }
    
        for(int i = 0; i<s.size(); i++)
        {
            cout << s[i] << " , ";
        }
    }
};

int main()
{
    Solution s1;
    vector<char> s = {'h','e','l','l','o'};
    s1.reverseString(s);
}
// for (std::vector<char>::const_iterator i = path.begin(); i != path.end(); ++i)
 //   std::cout << *i << ' ';