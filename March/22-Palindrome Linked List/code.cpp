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
    
    ListNode* reverseLinkedList(ListNode* head)
    {
        if(head == NULL || head->next == NULL) // [] or [1]
            return head;
        
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* nxt = head->next;
        
        while(current != NULL)
        {
            current->next = prev;
            prev = current;
            current = nxt;
            if(nxt != NULL) nxt = nxt->next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) 
    {
        if(head->next == NULL) return true; //[1]
        
        // Step1: find mid of LL
        //  O(n)
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* beforeSlow = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            beforeSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //Step2 : reverse LL from slow(middle) to end
        //  O(n)
        beforeSlow->next = reverseLinkedList(slow);
        
        //Step3: check for palindrome
        //  O(n)
        ListNode* start = head;
        ListNode* mid = beforeSlow->next;
        
        while(start != beforeSlow->next)
        {
            if(start->val != mid->val)
                return false;
            
            start = start->next;
            mid = mid->next;
        }
        return true;
    }
};

/*
n->nodes in Linked list
Time Complexity = O(n)
Space Complexity = O(1)
*/
