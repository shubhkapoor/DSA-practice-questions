/*      Postorder Tree Traversal       */

//recursive

void postorder(node* root)
{
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
}


// Iterative

void postorder(node* root)
{
    if(root==NULL)
        return;

    stack<node*> s;
    s.push(root);

    stack<int> out;

    while(!s.empty())
    {
        node* cur = s.top();
        s.pop();

        out.push(cur->data);

        if(cur->left)
            s.push(cur->left);

        if(cur->right)
            s.push(cur->right);
    }

    while(!out.empty())
    {
        cout<<out.top();
        out.pop();
    }
}
