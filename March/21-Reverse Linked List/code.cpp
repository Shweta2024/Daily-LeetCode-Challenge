/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL) // [] or [1]
            return head;
        
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* nxt = head->next;
        
        // O(n)
        while(current != NULL)
        {
            current->next = prev;
            prev = current;
            current = nxt;
            if(nxt != NULL) nxt = nxt->next;
        }
       return prev; 
    }
};
/*
n->nodes in Linked list
Time Complexity = O(n)
Space Complexity = O(1)*/
