/*        Left View of Binary Tree

Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function
leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

*/

//Function to return a list containing elements of left view of the binary tree.

vector<int> leftView(Node *root)
{
    // Your code here
    
    vector<int> ans;
    
    if(root == NULL)
        return ans;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        int n = q.size();
        
        for(int i=1 ; i<=n ; i++)
        {
            Node* temp = q.front();
            q.pop();
            
            if(i==1)
            {
                ans.push_back(temp->data);
            }
            
            if(temp->left)
            {
                q.push(temp->left);
            }
            
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return ans;
}
