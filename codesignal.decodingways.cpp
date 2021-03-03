#include<iostream>
using namespace std;
#include<vector>


// decoding ways

class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0 || s[0] == '0') return 0;
        if(s.length() == 1) return 1;
        
        int count1 = 1, count2 = 1;
        for(int i = 1; i < s.length(); ++i){
            int d = s[i] - '0';
            int dd = (s[i-1] - '0')*10 + d;
            int count = 0;
            if(d > 0) count += count2;
            if(dd >= 10 && dd <= 26) count += count1;
            count1 = count2;  // prev to prev
            count2 = count;  // count2 prev sol
        }
        return count2;
    }
};