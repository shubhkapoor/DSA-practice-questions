/*     Zig-Zag Tree Traversal 

Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

Example 1:

Input:
        3
      /   \
     2     1
Output:
3 1 2


Example 2:

Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 

*/

class Solution
{
public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        // Code here

        vector<int> ans;

        if(root==NULL)
        {
            return ans;
        }

        stack<Node*> s1;
        stack<Node*> s2;
        s1.push(root);
        bool leftToRight = true;

        while(!s1.empty())
        {
            Node* temp = s1.top();
            s1.pop();

            if(temp != NULL)
            {
                ans.push_back(temp->data);

                if(leftToRight)
                {
                    if(temp->left)
                    {
                        s2.push(temp->left);
                    }

                    if(temp->right)
                    {
                        s2.push(temp->right);
                    }
                }

                else
                {
                    if(temp->right)
                    {
                        s2.push(temp->right);
                    }

                    if(temp->left)
                    {
                        s2.push(temp->left);
                    }
                }
            }

            if(s1.empty())
            {
                leftToRight = !leftToRight;
                swap(s1,s2);
            }
        }

        return ans;
    }
};
