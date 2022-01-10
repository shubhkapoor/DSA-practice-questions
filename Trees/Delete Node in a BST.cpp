/*        Delete Node in a BST

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.

Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.

*/

class Solution
{
public:

    TreeNode* inorderSuccessor(TreeNode* root)
    {
        TreeNode* cur = root;

        while(cur && cur->left!=NULL)
        {
            cur = cur->left;
        }

        return cur;
    }

    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if(!root)
        {
            return NULL;
        }

        if(root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if(root->left == NULL)
            {
                TreeNode* temp = root->right;
                delete(root);
                return temp;
            }
            else if(root->right == NULL)
            {
                TreeNode* temp = root->left;
                delete(root);
                return temp;
            }
            else
            {
                TreeNode* temp = inorderSuccessor(root->right);
                swap(root->val, temp->val);
                root->right = deleteNode(root->right, key);
            }
        }

        return root;
    }
};
