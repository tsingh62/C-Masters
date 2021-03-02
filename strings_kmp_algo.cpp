// // C++ program to find a list in second list 
// #include <iostream> 
// using namespace std; 

// // A Linked List node 
// struct Node 
// { 
// 	int data; 
// 	Node* next; 
// }; 

// // Returns true if first list is present in second 
// // list 
// bool findList(Node* first, Node* second) 
// { 
// 	Node* ptr1 = first, *ptr2 = second; 

// 	// If both linked lists are empty, return true 
// 	if (first == NULL && second == NULL) 
// 		return true; 

// 	// Else If one is empty and other is not return 
// 	// false 
// 	if ( first == NULL || (first != NULL && second == NULL)) 
// 		return false; 

// 	// Traverse the second list by picking nodes 
// 	// one by one 
// 	while (second != NULL) 
// 	{ 
// 		// Initialize ptr2 with current node of second 
// 		ptr2 = second; 

// 		// Start matching first list with second list 
// 		while (ptr1 != NULL) 
// 		{ 
// 			// If second list becomes empty and first 
// 			// not then return false 
// 			if (ptr2 == NULL) 
// 				return false; 

// 			// If data part is same, go to next 
// 			// of both lists 
// 			else if (ptr1->data == ptr2->data) 
// 			{ 
// 				ptr1 = ptr1->next; 
// 				ptr2 = ptr2->next; 
// 			} 

// 			// If not equal then break the loop 
// 			else break; 
// 		} 

// 		// Return true if first list gets traversed 
// 		// completely that means it is matched. 
// 		if (ptr1 == NULL) 
// 			return true; 

// 		// Initialize ptr1 with first again 
// 		ptr1 = first; 

// 		// And go to next node of second list 
// 		second = second->next; 
// 	} 

// 	return false; 
// } 

// /* Function to print nodes in a given linked list */
// void printList(Node* node) 
// { 
// 	while (node != NULL) 
// 	{ 
// 		printf("%d ", node->data); 
// 		node = node->next; 
// 	} 
// } 

// // Function to add new node to linked lists 
// Node *newNode(int key) 
// { 
// 	Node *temp = new Node; 
// 	temp-> data= key; 
// 	temp->next = NULL; 
// 	return temp; 
// } 

// /* Driver program to test above functions*/
// int main() 
// { 
// 	/* Let us create two linked lists to test 
// 	the above functions. Created lists shall be 
// 		a: 1->2->3->4 
// 		b: 1->2->1->2->3->4*/
// 	Node *a = newNode(1); 
// 	a->next = newNode(2); 
// 	a->next->next = newNode(3); 
// 	a->next->next->next = newNode(4); 

// 	Node *b = newNode(1); 
// 	b->next = newNode(2); 
// 	b->next->next = newNode(1); 
// 	b->next->next->next = newNode(2); 
// 	b->next->next->next->next = newNode(3); 
// 	b->next->next->next->next->next = newNode(4); 

// 	findList(a,b) ? cout << "LIST FOUND" : 
// 					cout << "LIST NOT FOUND"; 

// 	return 0; 
// } 


// C++ program for implementation of KMP pattern searching 
// algorithm 
#include <iostream> 
using namespace std;
void computeLPSArray(char* pat, int M, int* lps); 

// Prints occurrences of txt[] in pat[] 
void KMPSearch(char* pat, char* txt) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 

	// create lps[] that will hold the longest prefix suffix 
	// values for pattern 
	int lps[M]; 

	// Preprocess the pattern (calculate lps[] array) 
	computeLPSArray(pat, M, lps); 

	int i = 0; // index for txt[] 
	int j = 0; // index for pat[] 
	while (i < N) { 
		if (pat[j] == txt[i]) { 
			j++; 
			i++; 
		} 

		if (j == M) { 
		//	printf("Found pattern at index %d ", i - j); 
			cout << "Pattern found at index " << i - j << endl;
			j = lps[j - 1]; 
		} 

		// mismatch after j matches 
		else if (i < N && pat[j] != txt[i]) { 
			// Do not match lps[0..lps[j-1]] characters, 
			// they will match anyway 
			if (j != 0) 
				j = lps[j - 1]; 
			else
				i = i + 1; 
		} 
	} 
} 

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(char* pat, int M, int* lps) 
{ 
	// length of the previous longest prefix suffix 
	int len = 0; 

	lps[0] = 0; // lps[0] is always 0 

	// the loop calculates lps[i] for i = 1 to M-1 
	int i = 1; 
	while (i < M) { 
		if (pat[i] == pat[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else // (pat[i] != pat[len]) 
		{ 
			// This is tricky. Consider the example. 
			// AAACAAAA and i = 7. The idea is similar 
			// to search step. 
			if (len != 0) { 
				len = lps[len - 1]; 

				// Also, note that we do not increment 
				// i here 
			} 
			else // if (len == 0) 
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 

// Driver program to test above function 
int main() 
{ 
	// char txt[] = "ABABDABACDABABCABAB"; 
	// char pat[] = "ABABCABAB"; 

	char txt[] = "GEEKS FOR GEEKS"; 
	char pat[] = "GEEK"; 
	KMPSearch(pat, txt); 
	return 0; 
} 
