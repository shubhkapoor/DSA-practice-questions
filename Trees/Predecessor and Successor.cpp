/*      Predecessor and Successor 

There is BST given with root node with key part as integer only. You need to find the inorder successor and predecessor of a given key. In case, if the either of predecessor
or successor is not found print -1.

*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively

Node* successor(Node* root)
{
    Node* temp = root->right;

    while(temp && temp->left)
    {
        temp = temp->left;
    }

    return temp;
}

Node* predecessor(Node* root)
{
    Node* temp = root->left;

    while(temp && temp->right)
    {
        temp = temp->right;
    }

    return temp;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    // Your code goes here

    if(root==NULL)
    {
        return;
    }

    if(root->key > key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else if(root->key < key)
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
    else if(root->key == key)
    {
        if(root->left)
            pre = predecessor(root);

        if(root->right)
            suc = successor(root);
    }
}
