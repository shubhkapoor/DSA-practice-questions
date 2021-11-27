/*     Longest Substring Without Repeating Characters

Given a string S, find the length of its longest substring that does not have any repeating characters.

Example 1:

Input:
S = geeksforgeeks
Output: 7
Explanation: The longest substring
without repeated characters is "ksforge".


Example 2:

Input:
S = abbcdb
Output: 3
Explanation: The longest substring is
"bcd". Here "abcd" is not a substring
of the given string.

*/

class Solution
{
public:
    // s is the given string
    int SubsequenceLength (string s)
    {
        // Your code goes here

        vector<int> v(256,-1);

        int n = s.size();
        int left=0, right=0;
        int len = 0;

        while(right<n)
        {
            if(v[s[right]]!=-1)
            {
                left = max(left,v[s[right]]+1);
            }

            v[s[right]] = right;

            len = max(len,right-left+1);

            right++;
        }

        return len;
    }
};
