/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool isPseudoPalindromic(vector<int>&count)
    {
        int oddFreq = 0;
        for(auto current : count)
        {
            if(current%2 == 1)
                oddFreq++;
            
            if(oddFreq > 1)
                return false;
        }
        return true;
    }
    
    void findTotalPseudoPalindromicPaths(TreeNode* root, int &ans, vector<int>&count)
    {
        if(root == NULL) return;
        
        count[root->val]++;
        findTotalPseudoPalindromicPaths(root->left,ans,count);
        findTotalPseudoPalindromicPaths(root->right,ans,count);
        
        // got a path
        if(root->left == NULL && root->right == NULL)
        {
            if(isPseudoPalindromic(count))
                ans++;
        }
        
        // undo changes
        count[root->val]--;
        return;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        int ans = 0;
        vector<int>count(10,0);
        
        findTotalPseudoPalindromicPaths(root,ans,count);
        
        return ans;
    }
};

/*
Time Complexity = O(N)
Space Complexity = O(h)
*/
