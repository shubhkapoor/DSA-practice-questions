/*        Height of Binary Tree

Given a binary tree, find its height.

Example 1:

Input:
     1
    /  \
   2    3
Output: 2


Example 2:

Input:
  2
   \
    1
   /
 3
Output: 3   

*/

//Function to find the height of a binary tree.
int height(struct Node* node)
{
    //code here
    
    if(node == NULL)
        return 0;
    
    int lh = height(node->left);
    int rh = height(node->right);
    
    return (lh>rh) ? lh + 1 : rh + 1;
}
