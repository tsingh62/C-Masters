#include<iostream>
using namespace std;

// * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */

// accepted code 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1=0, num2=0;
        ListNode *temp1 = l1, *temp2 = l2, *out = NULL, *tempout = NULL;
        int carry=0;
        
        while(temp1!=NULL || temp2!=NULL || carry){
            int ad = 0;
            if(temp1!=NULL){
                ad += temp1->val;
                temp1 = temp1->next;
            }
            if(temp2!=NULL){
                ad += temp2->val;
                temp2 = temp2->next;
            }
            ad += carry;
            int dig = ad%10;
            carry = ad/10;
             
            if(out==NULL){
                out = new ListNode(dig);
                tempout = out;
            }
            else{
               tempout->next =  new ListNode(dig);
                tempout = tempout->next;
            } 
        }
        return out;
    }
};




////////////////////////////////////////////////////
struct ListNode {

int val;
ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
ListNode *createNode(int val) {
return new ListNode(val);
}
/////---->>
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

 ListNode *result = NULL;
 if (!l1 || !l2)
     return result;
 
 // Point to the last digits of both numbers
 bool carry = 0;
 ListNode *retVal = createNode(0);
 result = retVal;
 
 // printf("retVal=%p\n", retVal);
 while (1) {
     int val1 = 0;
     int val2 = 0;
     
     if (l1)
         val1 = l1->val;
     if (l2)
         val2 = l2->val;
     
     int sum = val1 + val2 + carry;
     carry = (sum >= 10);
     int digit = sum % 10;
     
     result->val = digit;
     
     //printf("val1 = %d val2=%d result->val=%d carry=%d\n",
     //       val1, val2, result->val, carry);
     
     // printf("result->val=%d result->next=%p carry=%d\n",
     //       result->val, result->next, carry);
     
     if (l1)
         l1 = l1->next;
     if (l2)
         l2 = l2->next;
     
     // Terminating condition.
     if (!l1 && !l2 && !carry)
         break;
     
     // More to add.
     result->next = createNode(0);
     result = result->next;
 }
 
 return retVal;
}

};


////////////////////////////////////////////

// A C++ recursive program to add two linked lists
// A linked List Node
class Node {
public:
	int data;
	Node* next;
};

typedef Node node;

/* A utility function to insert
a node at the beginning of linked list */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node[(sizeof(Node))];

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* A utility function to print linked list */
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}

// A utility function to swap two pointers
void swapPointer(Node** a, Node** b)
{
	node* t = *a;
	*a = *b;
	*b = t;
}

/* A utility function to get size of linked list */
int getSize(Node* node)
{
	int size = 0;
	while (node != NULL) {
		node = node->next;
		size++;
	}
	return size;
}

// Adds two linked lists of same size
// represented by head1 and head2 and returns
// head of the resultant linked list. Carry
// is propagated while returning from the recursion
node* addSameSize(Node* head1, Node* head2, int* carry)
{
	// Since the function assumes linked lists are of same
	// size, check any of the two head pointers
	if (head1 == NULL)
		return NULL;

	int sum;

	// Allocate memory for sum node of current two nodes
	Node* result = new Node[(sizeof(Node))];

	// Recursively add remaining nodes and get the carry
	result->next
		= addSameSize(head1->next, head2->next, carry);

	// add digits of current nodes and propagated carry
	sum = head1->data + head2->data + *carry;
	*carry = sum / 10;
	sum = sum % 10;

	// Assigne the sum to current node of resultant list
	result->data = sum;

	return result;
}

// This function is called after the
// smaller list is added to the bigger
// lists's sublist of same size. Once the
// right sublist is added, the carry
// must be added toe left side of larger
// list to get the final result.
void addCarryToRemaining(Node* head1, Node* cur, int* carry,
						Node** result)
{
	int sum;

	// If diff. number of nodes are not traversed, add carry
	if (head1 != cur) {
		addCarryToRemaining(head1->next, cur, carry,
							result);

		sum = head1->data + *carry;
		*carry = sum / 10;
		sum %= 10;

		// add this node to the front of the result
		push(result, sum);
	}
}

// The main function that adds two linked lists
// represented by head1 and head2. The sum of
// two lists is stored in a list referred by result
void addList(Node* head1, Node* head2, Node** result)
{
	Node* cur;

	// first list is empty
	if (head1 == NULL) {
		*result = head2;
		return;
	}

	// second list is empty
	else if (head2 == NULL) {
		*result = head1;
		return;
	}

	int size1 = getSize(head1);
	int size2 = getSize(head2);

	int carry = 0;

	// Add same size lists
	if (size1 == size2)
		*result = addSameSize(head1, head2, &carry);

	else {
		int diff = abs(size1 - size2);

		// First list should always be larger than second
		// list. If not, swap pointers
		if (size1 < size2)
			swapPointer(&head1, &head2);

		// move diff. number of nodes in first list
		for (cur = head1; diff--; cur = cur->next)
			;

		// get addition of same size lists
		*result = addSameSize(cur, head2, &carry);

		// get addition of remaining first list and carry
		addCarryToRemaining(head1, cur, &carry, result);
	}

	// if some carry is still there, add a new node to the
	// fron of the result list. e.g. 999 and 87
	if (carry)
		push(result, carry);
}

// Driver code
int main()
{
	Node *head1 = NULL, *head2 = NULL, *result = NULL;

	int arr1[] = { 9, 9, 9 };
	int arr2[] = { 1, 8 };

	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);

	// Create first list as 9->9->9
	int i;
	for (i = size1 - 1; i >= 0; --i)
		push(&head1, arr1[i]);

	// Create second list as 1->8
	for (i = size2 - 1; i >= 0; --i)
		push(&head2, arr2[i]);

	addList(head1, head2, &result);

	printList(result);

	return 0;
}

// This code is contributed by rathbhupendra
