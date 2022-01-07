/*         Check for Balanced Tree 

Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

Example 1:

Input:
      1
    /
   2
    \
     3 
Output: 0
Explanation: The max difference in height
of left subtree and right subtree is 2,
which is greater than 1. Hence unbalanced

Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 1
Explanation: The max difference in height
of left subtree and right subtree is 1.
Hence balanced. 

*/

class Solution
{
public:
    //Function to check whether a binary tree is balanced or not.

    int f=1;

    int height(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        int lh = height(root->left);
        int rh = height(root->right);

        if(abs(lh-rh)>1)
        {
            f = 0;
        }

        return (lh>rh) ? (lh+1) : (rh+1);
    }

    bool isBalanced(Node *root)
    {
        //  Your Code here
        f = 1;
        height(root);
        return f;
    }
};
