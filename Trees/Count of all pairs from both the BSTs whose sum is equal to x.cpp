/*    Count of all pairs from both the BSTs whose sum is equal to x

Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x. Your task is to complete the function countPairs(), that returns the count of 
all pairs from both the BSTs whose sum is equal to x.

Example 1:

Input:
BST1:
       5
     /   \
    3     7
   / \   / \
  2   4 6   8

BST2:
       10
     /    \
    6      15
   / \    /  \
  3   8  11   18

x = 16
Output:
3
Explanation:
The pairs are: (5, 11), (6, 10) and (8, 8)

Example 2:

Input:
BST1:
  1
   \
    3
   /
  2
BST2:
    3
   / \
  2   4
 /     
1

x = 4
Output:
3
Explanation:
The pairs are: (2, 2), (3, 1) and (1, 3)

*/

//Method 1

class Solution
{
public:

    unordered_map<int,int> mp;

    void solve(Node* root)
    {
        if(root==NULL)
        {
            return;
        }

        solve(root->left);
        solve(root->right);
        mp[root->data]++;
    }

    void preorder(Node* root, int &count, int x)
    {
        if(root==NULL)
        {
            return;
        }

        if(mp.find(x - root->data) != mp.end())
        {
            count++;
        }

        preorder(root->left, count, x);
        preorder(root->right, count, x);
    }

    int countPairs(Node* root1, Node* root2, int x)
    {
        mp.clear();
        int count = 0;

        solve(root1);

        preorder(root2,count,x);

        return count;
    }
};


//Method 2

class Solution
{
public:
    int count;

    bool validate(Node* root2, int k)
    {
        if(root2==NULL)
        {
            return false;
        }

        if(root2->data==k)
        {
            return true;
        }

        bool x = false;
        bool y = false;

        if(k < root2->data)
        {
            x = validate(root2->left, k);
        }

        else if(k > root2->data)
        {
            y = validate(root2->right, k);
        }

        return x||y;
    }

    void solve(Node* root1, Node* root2, int x)
    {
        if(root1==NULL)
        {
            return;
        }

        solve(root1->left, root2, x);

        if( validate(root2, x - root1->data) )
        {
            count++;
        }

        solve(root1->right, root2, x);
    }

    int countPairs(Node* root1, Node* root2, int x)
    {
        count = 0;
        solve(root1, root2, x);
        return count;
    }
};
