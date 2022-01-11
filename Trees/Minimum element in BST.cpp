/*       Minimum element in BST 

Given a Binary Search Tree. The task is to find the minimum element in this given BST.

Example 1:

Input:
           5
         /    \
        4      6
       /        \
      3          7
     /
    1
Output: 1

Example 2:

Input:
             9
              \
               10
                \
                 11
Output: 9

*/

// Function to find the minimum element in the given BST.
int minValue(Node* root)
{
    // Code here

    if(root==NULL)
    {
        return 0;
    }

    Node* temp = root;

    while(temp && temp->left)
    {
        temp = temp->left;
    }

    return temp->data;
}
