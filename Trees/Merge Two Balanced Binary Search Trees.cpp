/*          Merge Two Balanced Binary Search Trees          */

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<int> vec;

void inorder_vec(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    inorder_vec(root->left);
    vec.push_back(root->data);
    inorder_vec(root->right);
}

Node* buildTree(int start, int end)
{
    if(start > end)
        return NULL;

    int mid = (start+end)/2;

    Node* root = new Node(vec[mid]);

    root->left = buildTree(start, mid-1);
    root->right = buildTree(mid+1, end);

    return root;
}

Node* mergeTrees(Node* root1, Node* root2, int m, int n)
{
    inorder_vec(root1);
    inorder_vec(root2);

    sort(vec.begin(), vec.end());

    Node* root = buildTree(0,m+n-1);
}

void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    Node *root1 = new Node(100);
    root1->left = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);

    Node *root2 = new Node(80);
    root2->left = new Node(40);
    root2->right = new Node(120);

    Node *root = mergeTrees(root1, root2, 5, 3);
    inorder(root);

    return 0;
}
