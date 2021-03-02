#include<iostream>
using namespace std;

bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {
    
    // Convert NumberA:
    int numberA = 0;
    // Leading zero check:
    bool isFirstCharA = true;
    
    for (std::string::size_type i = 0; i < crypt[0].size(); i++) {
        char a = crypt[0][i];
        
        // Iterate through solution:
        for (int j = 0; j < solution.size(); j++) {
        
            if (a == solution[j][0]) {
                numberA = (int)numberA*10 + (int)solution[j][1] - 48;

                if (isFirstCharA && crypt[0].size() != 1) {
                    if (solution[j][1] == '0') {
                        
                        return false;
                    }
                }
                isFirstCharA = false;
            }
        }
    }
    
    // Convert NumberB:
    int numberB = 0;
    // Leading zero check:
    bool isFirstCharB = true;
    for (std::string::size_type i = 0; i < crypt[1].size(); i++) {
        
        char b = crypt[1][i];
        // Iterate through solution:
        for (int j = 0; j < solution.size(); j++) {
            if (b == solution[j][0]) {
                numberB = (int)numberB*10 + (int)solution[j][1] - 48;
                
                if (isFirstCharB && crypt[1].size() != 1) {
                    if (solution[j][1] == '0') {
                     
                        return false;
                    }
                }
                isFirstCharB = false;
            }
        }
    }
    
    // Convert NumberC:
    int numberC = 0;
    // Leading zero check:
    bool isFirstCharC = true;
    for (std::string::size_type i = 0; i < crypt[2].size(); i++) {
        
        char c = crypt[2][i];
        // cout << c;
        // Iterate through solution:
        for (int j = 0; j < solution.size(); j++) {
            if (c == solution[j][0]) {
                numberC = (int)numberC*10 + (int)solution[j][1] - 48;
                
                if (isFirstCharC && crypt[2].size() != 1) {
                    if (solution[j][1] == '0') {
                        
                        return false;
                    }
                }
                isFirstCharC = false;
            }
        }
    }
    
    // Test if A + B = C
    if (numberA + numberB == numberC) {
        return true;
    }
    
    else return false;
}