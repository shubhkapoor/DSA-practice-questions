/*         Insert a node in a BST

Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST. 
Note: If K is already present in the BST, don't modify the BST.


Example 1:

Input:
     2
   /   \
  1     3
K = 4
Output: 1 2 3 4
Explanation: After inserting the node 4 
Inorder traversal will be 1 2 3 4.

Example 2:

Input:
        2
      /   \
     1     3
             \
              6
K = 4
Output: 1 2 3 4 6
Explanation: After inserting the node 4
Inorder traversal of the above tree
will be 1 2 3 4 6.

*/

// Function to insert a node in a BST.
Node* insert(Node* root, int key)
{
    // Your code here

    if(root==NULL)
    {
        return new Node(key);
    }

    if(root->data == key)
    {
        return root;
    }
    if(root->data > key)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }

    return root;
}
