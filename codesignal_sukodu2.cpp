#include<iostream>
using namespace std;

bool sudoku2(std::vector<std::vector<char>> grid) {

    // Always 9 x 9
    int size = 9;
    
    // FIRST, CHECK EACH ROW:

    for (int r1 = 0; r1 < size ; r1++) {
        
        // Store whether a #'s been seen:
        std::vector<int> beenSeen1(256,0);
        
        // Iterate through cols:
        for (int c1 = 0; c1 < size - 1; c1++) {
            
            if (grid[r1][c1] != '.') 
            {
                beenSeen1[(int)grid[r1][c1]] += 1;
            }
        }
        
        // Check for duplicates:
        for (int i1 = 0; i1 < beenSeen1.size(); i1++) 
        {
            if (beenSeen1[i1] > 1) 
            {
                return false;
            }
        }
        
    }
    
    // THEN CHECK EACH COL:

      for ( int c2 = 0; c2 < size ; c2++) {
        
        // Store whether #'s been seen:
        std::vector<int> beenSeen2(256,0);
        
        // Iterate through cols:
        for (int r2 = 0; r2 < size - 1; r2++) {
            
            if (grid[r2][c2] != '.') {
                beenSeen2[(int)grid[r2][c2]] += 1;
            }
        }
        
        // Check for duplicates:
        for (int i2 = 0; i2 < beenSeen2.size(); i2++) {
            if (beenSeen2[i2] > 1) {
                return false;
            }
        }
        
    }
    
    // THEN CHECK EACH QUADRANT:
    
    // Outer loops:
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            // index r = r + x*3
            // index c = c + y*3
            
            // Inner loops:
            std::vector<int> beenSeen3(256,0);
            
            for (int r3 = 0; r3 < 3; r3++) {
                for (int c3 = 0; c3 < 3; c3++) {
                    if (grid[r3 + x*3][c3 + y*3] != '.') {
                        beenSeen3[(int)grid[r3 + x*3][c3 + y*3]] += 1;
                    }
                }
            }
            
            // Check for duplicates:
            for (int i3 = 0; i3 < beenSeen3.size(); i3++) {
                if (beenSeen3[i3] > 1) {
                return false;
                }
            }
        }
    }

    
    return true;
}