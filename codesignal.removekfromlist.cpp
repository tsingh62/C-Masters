#include<iostream>
using namespace std;

//
 ListNode *slow=A, *prevslow=A, *fast=A;
    int flag = 0;
    //set location of fast ptr
    
    for(int i = 0; i < B; i++){
        fast = fast->next;
        if(fast == NULL){
            flag = 1;
            break;
        }
    }
    
    // if B > list size remove head element 
    if(flag) return A->next;
    
    // finding nth from last
    while(fast != NULL){
        fast = fast->next;
        prevslow = slow;
        slow = slow->next;
    }
    // slow ptr points to val to remove
    prevslow->next = slow->next;
    //slow->next = NULL;
    delete slow;
    return A;



// 1

ListNode* current = A;
ListNode* prev = NULL;
int count = 0;
if(A == NULL || B == 0) return A;
//Calculate length
while(current!=NULL)
{
    current = current->next;
    count++;
}

//If B is greater than or = to length, delete first Node
if(B >= count)
{
   A = A->next;
   return A;
}
int temp = count - B;
current = A;
//Traverse the list again till we reach the Node to be delete.
//Save the pointer to prev Node
//Update prev->next tp current->next and set NULL To current->next
while(temp)
{
    prev = current;
    current = current->next;
    temp--;
}
prev->next = current->next;
current->next = NULL;

return A;



// 2


ListNode *a = A;
    int n = 0;
 
    while(a != 0){
        n++;
        a = a->next;
    }
 
    a = A;
    if(B > n){
        A = A->next;
        cout << "B > n" << endl;
        delete a;
        return A;
    }
 
    if(n == 1){
        cout << a->val << endl;
        delete a;
    }
    else if(n > 1){
        int idx = n - B;
        int cnt = 0;
 
        while(cnt < idx - 1){
            a = a->next;
            cnt++;
        }
 
        ListNode *delPtr = a->next;
        a->next = delPtr->next;
        delete delPtr;
    }
 
    return A;

// // A linked list node
// class Node 
// {
// 	public:
// 		int data;
// 		Node* next;
// };

// // Given a reference (pointer) to the head 
// // of a list and an int, inserts a new node
// // on the front of the list
// Node* push(Node* head, int new_data)
// {
// 	Node* new_node = new Node();
// 	new_node->data = new_data;
// 	new_node->next = head;
// 	head = new_node;
// 	return head;
// }

// // Given a reference (pointer)to the head
// // of a list and a key, deletes all 
// // occurrence of the given key in 
// // linked list 
// Node* deleteKey(Node *head,int x)
// {
	
// 	// Store head node
// 	Node *tmp = head;
	
// 	while (head->data == x)
// 	{
// 		head = head->next;
// 	}
// 	while (tmp->next != NULL)
// 	{
// 		if (tmp->next->data == x)
// 		{
// 			tmp->next = tmp->next->next;
// 		}
// 		else
// 		{
// 			tmp = tmp->next;
// 		}
// 	}
// 	return head;
// }

// // This function prints contents of 
// // linked list starting from the
// // given node
// void printList(Node* node)
// {
// 	while (node->next != NULL) 
// 	{
// 		cout << node->data << " ";
// 		node = node->next;
// 	}
// 	cout << node->data;
// }

// // Driver code
// int main()
// {
	
// 	// Start with the empty list
// 	Node* head = NULL;
// 	head = push(head, 7);
// 	head = push(head, 2);
// 	head = push(head, 3);
// 	head = push(head, 2);
// 	head = push(head, 8);
// 	head = push(head, 1);
// 	head = push(head, 2);
// 	head = push(head, 2);
	
// 	// Key to delete
// 	int key = 2 ; 

// 	cout << "Created Linked List:\n ";
// 	printList(head);

// 	// Function call
// 	head = deleteKey(head, key);
// 	cout << "\nLinked List after Deletion is:\n";
	
// 	printList(head);
	
// 	return 0;
// }

// // // This code is contributed by shivamsharma2020




// // class Solution
// // {
// //     public:
// //     string removeKdigits(string num, int k)
// //     {
// //         if(k == num.length())
// //             return "0";

// //         int i = 0;
// //         while(k > 0){
// //             i = (i > 0) ? (i - 1) : 0;
// //             while(i < num.length()-1 && num[i] <= num[i+1])
// //                 i++;

// //             nu.erase(num.begin()+i);
// //             k--;
// //         }
// //         auto non_zero = num.find_first_not_of("0");
// //         num.erase(0, non_zero);

// //         if(num.length() == 0)
// //             return "0";

// //         return num;
// //     }
// // };