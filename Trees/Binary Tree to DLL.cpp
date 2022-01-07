/*       Binary Tree to DLL

Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively
in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head
node of the DLL.

Example 1:

Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3 
Explanation: DLL would be 3<=>1<=>2


Example 2:

Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40
Explanation:  DLL would be 
40<=>20<=>60<=>10<=>30

*/

// This function should return head to the DLL
class Solution
{
public:
    //Function to convert binary tree to doubly linked list and return it.

    void inorder(Node* root, Node* &head, Node* &prev, int &flag)
    {
        if(root==NULL)
        {
            return;
        }

        inorder(root->left, head, prev, flag);

        if(flag==0)
        {
            flag = 1;
            head = root;
            prev = root;
        }
        else
        {
            prev->right = root;
            prev->right->left = prev;
            prev = prev->right;
        }

        inorder(root->right, head, prev, flag);
    }

    Node * bToDLL(Node *root)
    {
        // your code here
        Node* head = NULL;
        Node* prev = NULL;
        int flag=0;

        inorder(root, head, prev, flag);

        return head;
    }
};
