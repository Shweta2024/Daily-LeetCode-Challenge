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
        while(current)
        {
            current = current->next;
            len++;
        }
        return len;
    }
    
    ListNode* middleNode(ListNode* head)
    {
        int len = findLength(head);
        
        int pos = len/2;
        
        ListNode* current = head;
        while(pos--)
            current = current->next;
        
        return current;
    }
};
