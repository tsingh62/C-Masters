#include <iostream> 
using namespace std; 
        
    /* Fills count array with 
    frequency of characters */
    void fillCharCounts(char *str, int *count) 
    { 
        int i; 
        for (i = 0; *(str + i); i++) 
        count[*(str + i)]++; 
    } 
  
    /* Print duplicates present  
    in the passed string */
    void printDups(char *str) 
    { 
          
        // Create an array of size 256 and fill 
        // count of every character in it 
        int *count = (int *)calloc(256,  sizeof(int)); 
        fillCharCounts(str, count); 
  
        // Print characters having count more than 0 
        int i; 
        for (i = 0; i < 256; i++) 
        if(count[i] > 1) 
        //    printf("%c, count = %d \n", i, count[i]); 
          cout << char(i) << " count  = " << count[i] << endl;
  
        free(count); 
    } 
 
  
/* Driver code*/
int main() 
{ 
   
    char str[] = "test string"; 
    printDups(str); 
    //getchar(); 
    return 0; 
} 

/* Calloc and malloc---->
The name malloc and calloc() are library functions that allocate memory dynamically. It means that memory is allocated during runtime(execution of the program) from the heap segment.

Initialization: malloc() allocates memory block of given size (in bytes) and returns a pointer to the beginning of the block. malloc() doesn’t initialize the allocated memory. If we try to access the content of memory block(before initializing) then we’ll get segmentation fault error(or maybe garbage values).
filter_none
brightness_4
void* malloc(size_t size); 
calloc() allocates the memory and also initializes the allocated memory block to zero. If we try to access the content of these blocks then we’ll get 0.

filter_none
brightness_4
void* calloc(size_t num, size_t size); 


// malloc() allocate the memory for 5 integers 
    // containing garbage values 
    arr = (int*)malloc(5 * sizeof(int)); // 5*4bytes = 20 bytes 
  
    // Deallocates memory previously allocated by malloc() function 
    free(arr); 
  
    // calloc() allocate the memory for 5 integers and 
    // set 0 to all of them 
    arr = (int*)calloc(5, sizeof(int)); 
  
    // Deallocates memory previously allocated by calloc() function 
    free(arr); 

*/