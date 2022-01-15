/*           k-th smallest element in BST 

Given a BST and an integer K. Find the Kth Smallest element in the BST. 

Example 1:

Input:
      2
    /   \
   1     3
K = 2
Output: 2

Example 2:

Input:
        2
      /  \
     1    3
K = 5
Output: -1

*/

class Solution
{
public:
    // Return the Kth smallest element in the given BST

    int ans;

    void solve(Node* root, int  k, int &count)
    {
        if(root==NULL)
        {
            return;
        }

        solve(root->left, k, count);

        if(count == k)
        {
            ans = root->data;
            count++;
            return;
        }
        else
        {
            count++;
        }

        solve(root->right, k, count);
    }

    int KthSmallestElement(Node *root, int k)
    {
        // add code here.

        int count = 1;
        ans = -1;
        solve(root, k, count);
        return ans;
    }
};
