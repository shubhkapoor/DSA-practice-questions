/*        Print all k-sum paths in a binary tree

A binary tree and a number k are given. Print every path in the tree with sum of the nodes in the path as k. 
A path can start from any node and end at any node and must be downward only, i.e. they need not be root node and leaf node; and negative numbers can also be there in the tree.
Examples: 
 

Input : k = 5  
        Root of below binary tree:
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
                       
Output :
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5 

*/

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

void func(Node* root, int k, vector<int> &v)
{
    if(root==NULL)
    {
        return;
    }

    v.push_back(root->data);

    func(root->left, k, v);
    func(root->right, k, v);

    int sum = 0;

    for(int i=v.size()-1 ; i>=0 ; i--)
    {
        sum += v[i];

        if(sum == k)
        {
            for(int j=i ; j<v.size() ; j++)
            {
                cout<<v[j]<<" ";
            }
            cout<<endl;
        }
    }

    v.pop_back();
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    int k = 5;
    vector<int> path;
    func(root, k,path);

    return 0;
}
