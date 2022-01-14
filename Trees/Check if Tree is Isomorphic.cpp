/*           Check if Tree is Isomorphic

Given two Binary Trees. Check whether they are Isomorphic or not.

Example 1:

Input:
 T1    1     T2:   1
     /   \        /  \
    2     3      3    2
   /            /
  4            4
Output: No

Example 2:

Input:
T1    1     T2:    1
    /  \         /   \
   2    3       3     2
  /                    \
  4                     4
Output: Yes

*/

class Solution
{
public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1, Node *root2)
    {
        //add code here.

        if(root1==NULL && root2==NULL)
        {
            return true;
        }

        if(root1==NULL || root2==NULL)
        {
            return false;
        }

        if(root1->data != root2->data)
        {
            return false;
        }

        bool a = isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
        bool b = isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);

        return a||b;
    }
};
