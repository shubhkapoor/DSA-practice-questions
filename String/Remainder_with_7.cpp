/*    Remainder with 7 

Given a number as string(n) , find the remainder of the number whe it is divided by 7

Example 1:

Input:
5
Output:
5
 

Example 2:

Input:
8
Output:
1

*/

class Solution
{
public:
    int remainderWith7(string n)
    {
        //Your code here
        int num=0;

        for(int i=0; i<n.length(); i++)
        {
            num = num*10 + (n[i] - '0');
            num %= 7;
        }

        return num;
    }
};
