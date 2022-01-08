/*       Leaf at same level

Given a Binary Tree, check if all leaves are at same level or not.

Example 1:

Input: 
            1
          /   \
         2     3

Output: 1

Explanation: 
Leaves 2 and 3 are at same level.

Example 2:

Input:
            10
          /    \
        20      30
       /  \        
     10    15

Output: 0

Explanation:
Leaves 10, 15 and 30 are not at same level.

*/

class Solution
{
public:
    /*You are required to complete this method*/

    int flag = 1;

    void solve(Node* root, int h, int &ma)
    {
        if(root==NULL)
        {
            return;
        }

        if(root->left==NULL && root->right==NULL)
        {
            if(ma==-1)
            {
                ma = h;
            }
            else if(ma != h)
            {
                flag = 0;
                return;
            }
        }

        solve(root->left, h+1, ma);
        solve(root->right, h+1, ma);
    }

    bool check(Node *root)
    {
        //Your code here

        flag=1;
        int ma = -1;
        int h = 0;
        solve(root,h,ma);
        return flag;
    }
};
