/*       Check for BST

Given the root of a binary tree. Check whether it is a BST or not.

Example 1:

Input:
   2
 /    \
1      3
Output: 1 
Explanation: 
The left subtree of root node contains node with key lesser than the root nodes key and the right subtree of root node contains node with key greater than the root nodes key.
Hence, the tree is a BST.

Example 2:

Input:
  2
   \
    7
     \
      6
       \
        5
         \
          9
           \
            2
             \
              6
Output: 0 
Explanation: 
Since the node with value 7 has right subtree nodes with keys less than 7, this is not a BST

*/

class Solution
{
public:
    //Function to check whether a Binary Tree is BST or not.

    void func(Node* root, Node* &prev, int &flag)
    {
        if(root==NULL)
        {
            return;
        }

        func(root->left, prev, flag);

        if(prev!=NULL && root->data <= prev->data)
        {
            flag = 0;
            return;
        }

        prev = root;

        func(root->right, prev, flag);
    }

    bool isBST(Node* root)
    {
        // Your code here
        int flag = 1;
        Node* prev = NULL;
        func(root,prev,flag);

        return flag;
    }
};
