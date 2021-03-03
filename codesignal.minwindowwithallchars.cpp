#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

string minWindow(string s, string t) {
        // An integer array to store the fequency of chars from t in S
        std::vector<int> freq(126, 0);
        for (char& ch : t) {
            freq[ch]++;
        }
        
        // Initialize the min substring length to a Max value and the
        // substring start character to -1
        int minsslength = INT_MAX;
        int ssstart = -1;
        // Variable to store matched char of t in S
        int countTinS = 0;
        // As the window is dynamic ie.., window shrinks and stretches,
        // two variables are needed
        int wstart = 0;
        
        // Loop for all characters in S
        for (int wend = 0; wend < s.length(); wend++) {
            // Decrement the frequecy of the character in t and if is in t, then
            // increment the countTinS
            if (--freq[s[wend]] >= 0) {
                countTinS++;
            }
            
            // Check to see if found all the variables in t
            while (countTinS == t.length()) {
                // Found all the characters in t, try to shrink the window and
                // find the min substring
                int length = wend - wstart + 1; // +1 is bcz the idx starts with 0
                if (minsslength > length) {
                    minsslength = length;
                    //substring = s.substr(wstart, length);
                    ssstart = wstart;
                }
                
                // Increment the freq of the char at wstart as this is needed in substring
                if (++freq[s[wstart]] > 0) {
                    // As this character is required, decrement the countTinS.
                    countTinS--;
                }
                // Shrink the window length by incrementing the widnow start
                wstart++;
            }
        }
        return ssstart == -1 ? "" : s.substr(ssstart, minsslength);
    }