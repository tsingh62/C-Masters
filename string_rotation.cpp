/*
A Program to check if strings are rotations of each other or not
________________________________________________________________

1. Create a temp string and store concatenation of str1 to
       str1 in temp.
                          temp = str1.str1
    2. If str2 is a substring of temp then str1 and str2 are 
       rotations of each other.

    Example:                 
                     str1 = "ABACD"
                     str2 = "CDABA"

     temp = str1.str1 = "ABACDABACD"
     Since str2 is a substring of temp, str1 and str2 are 
     rotations of each other.
*/
#include<iostream>
using namespace std; 
  
/* Function checks if passed strings (str1 
   and str2) are rotations of each other */
bool areRotations(string str1, string str2) 
{ 
   /* Check if sizes of two strings are same */
   if (str1.length() != str2.length()) 
        return false; 
  
   string temp = str1 + str1;  
  return (temp.find(str2) != string::npos); 
} 
  
/* Driver program to test areRotations */
int main() 
{ 
   string str1 = "ABACD", str2 = "CDABA"; 
   if (areRotations(str1, str2)) 
     cout << "Strings are rotations of each other" << endl; 
   else
      cout << "Strings are not rotations of each other" << endl; 
   return 0; 
} 

