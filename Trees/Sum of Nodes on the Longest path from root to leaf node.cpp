/*          Sum of Nodes on the Longest path from root to leaf node 

Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Example 1:

Input: 
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output: 13
Explanation:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3 
      /
     6

The highlighted nodes (4, 2, 1, 6) above are 
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13


Example 2:

Input: 
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
Output: 11

*/

class Solution
{
public:

    vector<int> solve(Node* root)
    {
        if(root==NULL)
        {
            return {0,0};
        }

        vector<int> a = solve(root->left);
        vector<int> b = solve(root->right);

        if(a[0] > b[0])
        {
            return {a[0]+1, a[1] + root->data};
        }

        else if(a[0] < b[0])
        {
            return {b[0]+1, b[1] + root->data};
        }

        else
        {
            return {a[0]+1, (max(a[1], b[1]) + root->data)};
        }
    }

    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        vector<int> ans = solve(root);
        // ans[0] ---> height   ,   ans[1] ---> sum
        return ans[1];
    }
};
