/*       Duplicate subtree in Binary Tree 

Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.


Example 1 :

Input : 
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5
Output : 1
Explanation : 
    2     
  /   \    
 4     5
is the duplicate sub-tree.


Example 2 :

Input : 
               1
             /   \ 
           2       3
Output: 0
Explanation: There is no duplicate sub-tree 
in the given binary tree.

*/

class Solution
{
public:
    /*This function returns true if the tree contains
    a duplicate subtree of size 2 or more else returns false*/

    unordered_map<string,int> mp;

    string solve(Node* root)
    {
        if(root==NULL)
        {
            return "$";
        }

        string s = "";

        if(root->right==NULL && root->left==NULL)
        {
            s = to_string(root->data);
            return s;
        }

        s = s + to_string(root->data);
        s = s + solve(root->left);
        s = s + solve(root->right);

        mp[s]++;

        return s;
    }

    int dupSub(Node *root)
    {
        // code here
        mp.clear();
        solve(root);

        for(auto it : mp)
        {
            if(it.second>=2)
            {
                return 1;
            }
        }
        return 0;
    }
};
