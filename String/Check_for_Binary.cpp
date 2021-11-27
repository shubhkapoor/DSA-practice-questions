/*    Check for Binary

Given a non-empty sequence of characters str, return true if sequence is Binary, else return false

Example 1:

Input:
str = 101
Output:
1

*/

bool isBinary(string str)
{
    // Your code here

    int cnt=0;

    for(int i=0; i<str.length(); i++)
    {
        if(str[i]=='0' || str[i]=='1')
            continue;
        else
            return 0;

    }

    return 1;
}
