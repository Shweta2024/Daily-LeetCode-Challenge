/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        unordered_map<ListNode*,bool>memo;
        ListNode* current = head;
        
        while(current)
        {
            // cycle exists
            if(memo[current])
                return true;
            
            memo[current] = true;
            current = current->next;
        }
        return false;
    }
};
/*
n -> number of nodes
Time complexity = O(n)
Space Complexity = O(n)*/
