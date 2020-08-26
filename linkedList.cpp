#include<iostream>
using namespace std;

// linked list

class listNode
{
	public:

	int val;
	listNode *next;

	// constructor
	listNode(int val)
	{
		this->val=val;
		this->next=NULL; // next address is by default null
	}
};

// if we want to see changes in the function call
// then we pass it by ref as - we can see the 
// changes in the fun as well as the func--
// else it would just print NULL as the main()
// has head defined as NULL
	void insertAtHead(listNode *&head, int data)
	{
		cout << "Insert function has started" << endl;
		// creating a new node dynamically
		listNode *n = new listNode(data);
		n->next=head; // n->next points to the old head when we insert new node at the front
		head = n; // making n (new node) as the head node
		cout << "Insert function has ended" << endl;
	}
	
	// if you want to see the changes in the head
	// you can pass the head as by ref
   // void display(listNode *&head)
	void display(listNode *head)
	{
		listNode *temp = head;

		while(temp !=NULL)
		{
			cout << temp->val << " ";
			temp = temp->next; 
		}
		cout << "NULL" << endl;
	//********************************//
	// the head inside this function is the copy of
	// the head inside the main function

		// while(head !=NULL)
		// {
		// 	cout << head->val << " -> ";
		// 	head = head->next;
		// }
		// cout << "NULL" << endl;
	}
 
 // length of the linked list

 int size(listNode* head)
 {
	 listNode *temp = head;
	 int len =0;

	 while(temp!=NULL)
	 {
		 len++;
		 temp = temp->next;
	 }
	 return len;
 }
 // insert at tail

 void insertAtTail(listNode *&head, int data)
 {
	 if(head == NULL)
	 {
		 // no node inside the linked list
		 // no diff between insert at head and tail
		 insertAtHead(head, data);
		 return;

	 }
	 listNode *n = new listNode(data);
	 listNode *temp = head;

	 while(temp->next!=NULL)
	 {
		 temp=temp->next;
	 }
	 // now you are at the last node of your current linked list
	 temp->next = n;
 }
 // insert at any index

 void insertAtAnyIndex(listNode *&head, int data, int pos)
 {
	 // edge case
	 if(pos <=1 || head == NULL)
	 {
		 insertAtHead(head, data);
		 return;
	 }
	 if(pos >= size(head))
	 {
		 insertAtTail(head,data);
	 }

	 listNode *temp = head;
	 int jump=1;

	 while(jump < pos-1)
	 {
		 temp = temp->next;
		 jump++;
	 }
	 listNode *n = new listNode(data); 
	 n->next = temp->next;
	 temp->next = n;
 }

 void deleteAtHead(listNode *&head)
{
	// edge case
	if(head ==NULL)
	{
		return;
	}

	listNode *toBeDeleted = head;
	head = head->next;
	delete toBeDeleted;
}

void deleteAtTail(listNode *&head)
{
	// edge case
	if(head == NULL)
	{
		return;
	}
	if(head->next==NULL)
	{
		deleteAtHead(head);
		return;
	}
	listNode *temp = head;
	while(temp->next->next!=NULL)
	{
		temp = temp->next;
	}
	listNode *tobeDeleted = temp->next;
	temp->next = NULL;
	delete tobeDeleted;
}
bool search(listNode *head, int key)
{
	listNode *temp = head;

	while(temp!=NULL)
	{
		if(temp->val==key)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void deleteAtAYnyIndx(listNode *&head, int pos)
{
	// edge case
	if(head == NULL || head->next==NULL || pos <=1)
	{
		deleteAtHead(head);
		return;
	}
	if(pos >= size(head))
	{
		deleteAtTail(head);
		return;
	}
	int jump =1;
	listNode *temp = head;

	while(jump<pos-1)
	{
		jump++;
		temp=temp->next;
	}
	listNode *tobedeleted = temp->next;
	temp->next= temp->next->next; // or tobedeleted->next;
	delete tobedeleted;
}

// return the address of the mid-point node
listNode* midPoint(listNode* head) 
{
	listNode *slow = head;
	listNode *fast = head;
	// ODD.            // EVEN
	while (fast->next != NULL and fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

// reverse recurssive
listNode *reverseRecrusive(listNode *head)
{
	// base case 
	if(head==NULL or head->next==NULL)
	{
		return head;
	}

	listNode *newHead = reverseRecrusive(head->next);

	// my work
	listNode *curr = head;
	curr->next->next = curr;
	curr->next = NULL;
	return newHead;
	
}

// reverse iterative 

listNode *reverseItr(listNode *head)
{
	listNode *prev = NULL;
	listNode *curr = head;
	while(curr!=NULL)
	{
		listNode *n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;
	}
	return prev;
}

// merge two linked list
// sorted

listNode *merge(listNode *a, listNode *b)
{
	// base call
	if(a==NULL)
	{
		return b;
	}
	if(b==NULL)
	{
		return a;
	}
	
	//rec
	listNode *newhead;
	if(a->val < b->val)
	{
		newhead = a;
		newhead->next = merge(a->next, b);
	}
	else
	{
		newhead = b;
		newhead->next = merge(a, b->next);
	}
	return newhead;
}
// k - reverse 
listNode *kReverse(listNode *head, int k)
{
	// base case
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	// iterative
	listNode *prev = NULL;
	listNode *curr = head;
	int steps =1;
	
	while(steps <=k && curr!=NULL)
	{
		listNode *n = curr->next;
		curr->next = prev;
		prev=curr;
		curr =n;
		steps++;
	}
	// rec 
	head->next = kReverse(curr, k);
	listNode *newHead = prev;
	return newHead;
}

int main()
{
	listNode *head=NULL; // by deault head is null when no list is created

	insertAtTail(head,123);
	display(head);
	
	insertAtHead(head,2);
	insertAtHead(head,4);
	insertAtHead(head,6);
	insertAtHead(head,9);
	display(head);

	
	cout <<size(head) << endl;

	insertAtTail(head,23);
	insertAtTail(head,45);
	display(head);

	// insertAtAnyIndex(head,18,3);

	// display(head);
	// cout <<size(head) << endl;

	// deleteAtHead(head);
	// display(head);

	// deleteAtTail(head);
	// display(head);

	// search(head, 23);

	// insertAtAnyIndex(head, 97, 5);
	// display(head);
	// deleteAtAYnyIndx(head, 4);
	// display(head);

	// // midpoint
	
	// listNode* mid = midPoint(head);
	// cout << mid->val << endl;

	
	// deleteAtAYnyIndx(head,3);

	// display(head);

	// mid = midPoint(head);
	// cout << mid->val << endl;

	// // // reverse recursive 
	// head = reverseRecrusive(head);
	// display(head);

	// // reverse iterative 
	// head = reverseItr(head);
	// display(head);

	// merge two sorted linked list

	listNode *head1= NULL;

	insertAtTail(head1, 1);
	insertAtTail(head1, 3);
	insertAtTail(head1, 5);
	insertAtTail(head1, 8);
	insertAtTail(head1, 9);


	listNode *head2= NULL;

	insertAtTail(head2, 2);
	insertAtTail(head2, 4);
	insertAtTail(head2, 6);
	
	cout << "first linked list" << endl;
	display(head1);

	cout << "Second linked list" << endl;
	display(head2);

	listNode *mergelist = merge(head1, head2);
	cout << "merged list " << endl;
	display(mergelist);

	// k - reverse
	listNode *head3= NULL;

	insertAtTail(head3, 1);
	insertAtTail(head3, 2);
	insertAtTail(head3, 3);
	insertAtTail(head3, 5);
	insertAtTail(head3, 6);
	insertAtTail(head3, 7);
	insertAtTail(head3, 8);
	insertAtTail(head3, 9);


	cout << "Before *********** "  << endl;
	display(head3);

	head3 = kReverse(head3, 3);

	cout << "After ***********" << endl;
	display(head3);

	return 0;
}
