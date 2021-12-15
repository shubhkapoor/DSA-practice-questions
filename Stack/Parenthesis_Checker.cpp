/*       Parenthesis Checker

Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

Example 1:

Input:
{([])}
Output: 
true
Explanation: 
{ ( [ ] ) }. Same colored brackets can form 
balaced pairs, with 0 number of 
unbalanced bracket.

Example 2:

Input: 
()
Output: 
true
Explanation: 
(). Same bracket can form balanced pairs, 
and here only 1 type of bracket is 
present and in balanced way.

Example 3:

Input: 
([]
Output: 
false
Explanation: 
([]. Here square bracket is balanced but 
the small bracket is not balanced and 
Hence , the output will be unbalanced.

*/

class Solution
{
public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here

        stack<char> s;
        int n = x.length();

        for(int i=0; i<n; i++)
        {
            if(x[i]=='{' || x[i]=='[' || x[i]=='(')
            {
                s.push(x[i]);
                continue;
            }

            if(s.empty())
            {
                return false;
            }

            switch(x[i])
            {
            case '}':
            {
                char ch = s.top();
                s.pop();
                if(ch=='(' || ch=='[')
                {
                    return false;
                }
                break;
            }

            case ')':
            {
                char ch = s.top();
                s.pop();
                if(ch=='{' || ch=='[')
                {
                    return false;
                }
                break;
            }

            case ']':
            {
                char ch = s.top();
                s.pop();
                if(ch=='(' || ch=='{')
                {
                    return false;
                }
                break;
            }
            }
        }

        return s.empty();
    }

};
