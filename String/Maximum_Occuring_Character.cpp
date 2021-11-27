/*     Maximum Occuring Character 

Given a string str. The task is to find the maximum occurring character in the string str. If more than one character occurs the maximum number of time then print the 
lexicographically smaller character.

Example 1:

Input:
str = testsample
Output: e
Explanation: e is the character which
is having the highest frequency.

Example 2:

Input:
str = output
Output: t
Explanation:  t and u are the characters
with the same frequency, but t is
lexicographically smaller.

*/

class Solution
{
public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here

        map<char,int> mp;

        for(int i=0; i<str.length(); i++)
        {
            mp[str[i]]++;
        }

        char ch;
        int max=-1;

        for(auto it:mp)
        {
            if(max < it.second)
            {
                max = it.second;
                ch=it.first;
            }
        }
        return ch;
    }
};
