/*       Kth largest element in BST

Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

Example 1:

Input:
      4
    /   \
   2     9
k = 2 
Output: 4

Example 2:

Input:
       9
        \ 
          10
K = 1
Output: 10

*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
public:

    int ans;

    void solve(Node* root, int k, int &count)
    {
        if(root==NULL)
        {
            return;
        }

        solve(root->right, k, count);

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

        solve(root->left, k, count);
    }

    int kthLargest(Node *root, int k)
    {
        //Your code here
        ans=-1;
        int count=1;
        solve(root,k,count);
        return ans;
    }
};
