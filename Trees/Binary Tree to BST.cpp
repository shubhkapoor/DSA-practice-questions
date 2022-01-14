/*         Binary Tree to BST

Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
 

Example 1:

Input:
      1
    /   \
   2     3
Output: 1 2 3

Example 2:

Input:
          1
       /    \
     2       3
   /        
 4       
Output: 1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1

*/

class Solution
{
public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST

    void inorder(Node* root, vector<int> &v)
    {
        if(root==NULL)
        {
            return;
        }

        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    void inorder_bst(Node* root, vector<int> v, int &i)
    {
        if(root==NULL)
        {
            return;
        }

        inorder_bst(root->left, v, i);

        root->data = v[i];
        i++;

        inorder_bst(root->right, v, i);
    }

    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here

        if(root == NULL)
        {
            return NULL;
        }

        vector<int> v;
        inorder(root,v);

        sort(v.begin(),v.end());

        int i=0;
        inorder_bst(root, v, i);

        return root;
    }
};
