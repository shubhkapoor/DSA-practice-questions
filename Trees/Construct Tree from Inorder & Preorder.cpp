/*         Construct Tree from Inorder & Preorder

Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1


Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5

*/

class Solution
{
public:

    int idx = 0;

    int search(int in[], int start, int end, int cur)
    {
        for(int i=start; i<=end; i++)
        {
            if(in[i] == cur)
            {
                return i;
            }
        }

        return -1;
    }

    Node* constructTree(int in[], int pre[], int start, int end)
    {
        if(start > end)
        {
            return NULL;
        }

        int cur = pre[idx];
        idx++;

        Node* temp = new Node(cur);

        int pos = search(in, start, end, cur);

        if(start==end)
        {
            return temp;
        }

        temp->left = constructTree(in, pre, start, pos-1);
        temp->right = constructTree(in, pre, pos+1, end);

        return temp;
    }

    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        Node* root = constructTree(in, pre, 0, n-1);

        return root;
    }
};
