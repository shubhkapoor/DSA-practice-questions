/*       Min distance between two given nodes of a Binary Tree 

Given a binary tree and two node values your task is to find the minimum distance between them.

Example 1:

Input:
        1
      /  \
     2    3
a = 2, b = 3

Output: 2

Explanation: The tree formed is:
       1
     /   \ 
    2     3
We need the distance between 2 and 3.
Being at node 2, we need to take two
steps ahead in order to reach node 3.
The path followed will be:
2 -> 1 -> 3. Hence, the result is 2.

*/

class Solution
{
public:
    /* Should return minimum distance between a and b
    in a tree with given root*/

    Node* LCA(Node* root, int n1, int n2)
    {
        if(root==NULL)
        {
            return NULL;
        }

        if(root->data==n1 || root->data==n2)
        {
            return root;
        }

        Node* leftLca = LCA(root->left, n1, n2);
        Node* rightLca = LCA(root->right, n1, n2);

        if(leftLca && rightLca)
        {
            return root;
        }

        if(leftLca!=NULL)
        {
            return leftLca;
        }

        if(rightLca!=NULL)
        {
            return rightLca;
        }
    }

    int dist(Node* root, int d, int k)
    {
        if(root==NULL)
        {
            return -1;
        }

        if(root->data==k)
        {
            return d;
        }

        int left = dist(root->left, d+1, k);

        if(left != -1)
        {
            return left;
        }
        else
        {
            return dist(root->right, d+1, k);
        }
    }

    int findDist(Node* root, int a, int b)
    {
        // Your code here

        Node* lca = LCA(root, a, b);
        int d1 = dist(lca, 0, a);
        int d2 = dist(lca, 0, b);

        return (d1+d2);
    }
};
