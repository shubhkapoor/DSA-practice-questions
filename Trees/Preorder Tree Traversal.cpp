/*      Preorder Tree Traversal       */

//Recursive

void preorder(node* root)
{
    if(root==NULL)
        return;

    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}


//Iterative

void preorder(node* root)
{
    stack<node*> s;
    s.push(root);

    while(!s.empty())
    {
        node* cur = s.top();
        s.pop();

        cout<<cur->data;
        if(cur->right)
            s.push(cur->right);

        if(cur->left)
            s.push(cur->left);
    }
}
