/*      Evaluation of Postfix Expression

Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators
like *, /, + and -.

Example 1:

Input: S = "231*+9-"
Output: -4
Explanation:
After solving the given expression, 
we have -4 as result.

Example 2:

Input: S = "123+*8-"
Output: -3
Explanation:
After solving the given postfix 
expression, we have -3 as result.

*/

class Solution
{
public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here

        stack<int> s;

        for(int i=0; i<S.length(); i++)
        {
            if(isdigit(S[i]))
            {
                s.push(S[i] - '0');
            }
            else
            {
                int val1 = s.top();
                s.pop();

                int val2 = s.top();
                s.pop();

                switch(S[i])
                {
                case '+':
                    s.push(val2 + val1);
                    break;

                case '-':
                    s.push(val2 - val1);
                    break;

                case '*':
                    s.push(val2 * val1);
                    break;

                case '/':
                    s.push(val2 / val1);
                    break;
                }
            }
        }

        return s.top();
    }
};
