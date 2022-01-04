/*          Level order traversal

Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.

Example 1:

Input:
    1
  /   \ 
 3     2
Output:1 3 2


Example 2:

Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:10 20 30 40 60

*/

class Solution
{
public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
        //Your code here

        vector<int> ans;

        queue<Node*> q;
        q.push(node);
        q.push(NULL);

        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();

            if(temp != NULL)
            {
                ans.push_back(temp->data);

                if(temp->left)
                    q.push(temp->left);

                if(temp->right)
                    q.push(temp->right);
            }
            else if(!q.empty())
            {
                q.push(NULL);
            }
        }

        return ans;
    }
};
