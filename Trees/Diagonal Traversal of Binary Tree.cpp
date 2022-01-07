/*        Diagonal Traversal of Binary Tree

Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.

Example 1:

Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4

*/

// method 1

vector<int> diagonal(Node *root)
{
    // your code here
    vector<int> ans;

    if(root == NULL)
        return ans;

    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);

    while(!s1.empty())
    {
        Node* tmp = s1.top();
        s1.pop();

        if(tmp!=NULL)
        {
            ans.push_back(tmp->data);

            if(tmp->left)
                s2.push(tmp->left);

            if(tmp->right)
                s1.push(tmp->right);
        }

        if(s1.empty() && !s2.empty())
        {
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    return ans;
}


// method 2

vector<int> diagonal(Node *root)
{
    // your code here

    vector<int> ans;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        while(temp)
        {
            ans.push_back(temp->data);

            if(temp->left)
            {
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
    return ans;
}
