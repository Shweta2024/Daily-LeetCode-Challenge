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
    
    // function to find ancestors
    void findAncestor(TreeNode* root, TreeNode* parent, vector<int>current, 
                      unordered_map<TreeNode*, vector<int>>&ancestors)
    {
        if(!root) return;
        
        current.push_back(parent->val);
        ancestors[root] = current;
        
        findAncestor(root->left,root,current,ancestors);
        findAncestor(root->right,root,current,ancestors);
    }
    
    int maxAncestorDiff(TreeNode* root) 
    {
        unordered_map<TreeNode*, vector<int>>ancestors;
        vector<int>current;
        
        findAncestor(root->left,root,current,ancestors);
        findAncestor(root->right,root,current,ancestors);     
        
        int maxDifference = INT_MIN;
        for(auto current : ancestors)
        {
            TreeNode* currentNode = current.first;
            for(auto ancestorNode : current.second)
            {
                int currentDifference = abs(currentNode->val - ancestorNode);
                maxDifference = max(maxDifference, currentDifference);
            }
        }
        return maxDifference;
    }
};

/*
Time Complexity = O(N)
Space Complexity = O(N)
*/
