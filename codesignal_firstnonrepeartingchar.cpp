#include<iostream>
using namespace std;
#include<unordered_map>

char firstNotRepeatingCharacter(std::string s) 
{
    unordered_map<char, int> c;

    for(int i = 0; i < s.length(); i++)

        if(c.find(s[i]) != c.end())

            c[s[i]]++;
        else

            c.insert(make_pair(s[i], 1));
    
    for(int i = 0; i < s.length(); i++)

        if(c[s[i]] == 1)
        
            return s[i];    
    
    return '_';
}