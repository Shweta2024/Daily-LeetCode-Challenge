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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode* current = list1;
        ListNode* from = NULL; // to store the a-1 th node
        ListNode* to = NULL; // store part after b
        
        int i = 0;
        // O(n)
        while(i <= b)
        {
            if(i == a-1)
                from = current;
            else if(i == b)
                to = current->next;
            current = current->next;
            i++;
        }
        current = list2;
        // O(m)
        while(current->next != NULL)
            current = current->next;
        
        from->next = list2;
        current->next = to;
        return list1;
    }
};
/*
n->size of list1
m->size of list2
Time Complexity = O(n+m)
Space Complexity = O(1)
*/
