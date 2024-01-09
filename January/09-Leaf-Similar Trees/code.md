## Approach:-

1. We'll take two strings ``leafOfR1`` and ``leafOfR2``, that will store the values of leaf nodes of root1 and root2 respectively.
2. If the values of ``leafOfR1`` and ``leafOfR2`` are equal we'll return true otherwise we'll return false.

<br>

#### Why I'm adding a ``":"`` after adding value of leaf node in : ``leafNodes += to_string(root->val) + ":";``?


The reason why I am adding ``":"`` after adding the values of each node to ``leafNodes`` is that, if I have two trees such that:

the leaf nodes of the 1st tree are: 4,6,11,8 

and the leaf nodes of 2nd tree are 4,6,1,18.

Now, if we don't add a separator i.e. ``":"`` after each node value then,

we'll get the value of leafOfR1 as "46118" 
and leafOfR2 as "46118" and hence when we check if they are equal or not, then it will return a true, but it is wrong, they are not leaf similar, 
therefore after adding values of each node, we'll add a separator as ":".


<br>


## Complexity Analysis:-

- m -> total nodes in tree1

- n -> total nodes in tree2


1. Time Complexity =O(m+n), since we are iterating over all the m-nodes of tree1 and all the n nodes of tree2


2. Space Complexity = O(m+n) , Since we are using two strings to store the leaf nodes of both the trees

```cpp

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
    
    void findLeafNodes(TreeNode* root, string &leafNodes)
    {
        // we got a leaf node, so add it to the string leafNodes
        if(root->left == NULL && root->right == NULL)
        {
            leafNodes += to_string(root->val) + ":";
            return;
        }

        // make a left call ONLY if left of root exits
        if(root->left)
            findLeafNodes(root->left,leafNodes);

        // make a right call ONLY if right of root exits
        if(root->right)
            findLeafNodes(root->right,leafNodes);
        
        return ;
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        string leafOfR1 = ""; //  stores the leaf nodes of root1
        findLeafNodes(root1,leafOfR1);

        string leafOfR2 = "";  // stores the leaf nodes of root2
        findLeafNodes(root2,leafOfR2);

        // cout<<leafOfR1<<" - "<<leafOfR2<<endl;

        //  returns true if the leaf nodes of the both the tree are similar else returns false.
        return leafOfR1 == leafOfR2;
    }
};

```
