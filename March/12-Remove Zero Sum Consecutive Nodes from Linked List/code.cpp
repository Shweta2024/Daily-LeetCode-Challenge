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
    ListNode* removeZeroSumSublists(ListNode* head) 
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = head;
        
        // O(n)
        unordered_map<int,ListNode*>memo; // prefixSum : node
        int prefixSum = 0;
        memo[prefixSum] = dummy; // [1,-1]
        
        // O(n)
        while(current != NULL)
        {
            prefixSum += current->val;
            
            // found out a part that has 0 sum
            // remove it
            if(memo[prefixSum])
            {
                ListNode* from = memo[prefixSum];
                ListNode* to = from->next;
                
                int sum = prefixSum + to->val;
                while(sum != prefixSum)
                {
                    memo.erase(sum);
                    to = to->next;
                    sum += to->val;
                }
                from->next = current->next;
            }
            else
                memo[prefixSum] = current;
            current = current->next;
        } 
        return dummy->next;
    }
};
/*
n -> number of nodes in the linked list
Time Complexity = O(n)
Space Complexity = O(n)*/
