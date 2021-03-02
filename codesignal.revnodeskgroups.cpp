#include<iostream>
using namespace std;

// reverse nodes in k groups

// 1

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k == 1) return head;
        int n = 0; // count
        ListNode *curr = head;
        while(curr){
            n++;
            curr = curr->next;
        }
        
        ListNode *prev = nullptr, *next, *newHead; 
        ListNode *t1 = nullptr, *t2 = head;
        curr = head;
        
        while(n >= k){
            for(int i = 0; i < k; i++){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            if(!newHead) newHead = prev;
            if(t1) t1->next = prev;
            t2->next = curr; // n is not multiple of k
            t1 = t2;
            t2 = curr;
            prev = nullptr;
            n -= k;
        }
        return newHead;
    }
};

// 2

ListNode* reverseKGroup(ListNode* head, int k) 
{
    if(head == NULL || k == 1)
    return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    int cnt=0;
    ListNode *cur = dummy, *pre = dummy, *nex = dummy;
    while(cur->next != NULL) 
    {
        cur = cur->next;
        cnt++;
    }
    while(cnt>=k) 
    {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;i++) 
        {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
            pre = cur;
            cnt -= k;
    }
    return (dummy->next);
}