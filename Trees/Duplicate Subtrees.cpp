/*         Duplicate Subtrees

Given a binary tree of size N, your task is to that find all duplicate subtrees from the given binary tree.

Example:

Input : 

Output : 2 4
         4
Explanation: Above Trees are two duplicate subtrees.i.e  and Therefore,you need to return above trees root in the form of a list.

*/

unordered_map<string,int> mp;
vector<Node*> ans;

string solve(Node* root)
{
    if(root==NULL)
    {
        return "$";
    }

    string s = "";

    s = s + solve(root->left);
    s = s + solve(root->right);
    s = s + to_string(root->data);

    mp[s]++;

    if(mp[s] == 2)
    {
        ans.push_back(root);
    }

    return s;
}

vector<Node*> printAllDups(Node* root)
{
    // Code here
    ans.clear();
    mp.clear();
    solve(root);

    return ans;
}
