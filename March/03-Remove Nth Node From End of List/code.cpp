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
    
    
    int findLength(ListNode* head)
    {
        int len = 0;
        ListNode* current = head;
        
        // O(M)
        while(current)
        {
            current = current->next;
            len++;
        }
        return len;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int len = findLength(head);
        
        if(len == n)
            return head->next;
        
        int startPos = len - n - 1;
        ListNode* current = head;
        
        while(startPos--)
            current = current->next;
        
        current->next = current->next->next;
        
        return head;
    }
};
/*
M -> length of linked list
Time Complexity = O(M)
Space Complexity = O(1)
*/
