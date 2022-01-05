/*        Inorder Tree Traversal          */

// Iterative

void inorder(node* root)
{
    stack<node*> s;

    node* cur = root;

    while(!s.empty() || cur!=NULL)
    {
        if(cur!=NULL)
        {
            s.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = s.top();
            s.pop();
            cout<<cur->data;
            cur = cur->right;
        }
    }
}


// Recursive

void inorder(node* root)
{
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
