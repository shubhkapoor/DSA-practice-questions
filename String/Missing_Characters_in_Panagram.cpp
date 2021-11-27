/*     Missing Characters in Panagram

You are given a string s. You need to find the missing characters in the string to make a panagram ( a sentence using every letter of english alphabet at least once ).
Note: The output characters will be lowercase and lexicographically sorted.

Example 1:

Input:
s = Abcdefghijklmnopqrstuvwxy
Output: z
 

Example 2:

Input:
s = Abc
Output: defghijklmnopqrstuvwxyz

*/

class Solution
{
public:
    string missingPanagram(string str)
    {

        //Your code here

        string ans = "";

        map<char,bool> mp;

        for(int i=0; i<str.size(); i++)
        {
            mp[tolower(str[i])] = true;
        }

        for(char ch='a'; ch<='z'; ch++)
        {
            if(mp.find(ch)==mp.end())
            {
                ans = ans + ch;
            }
        }

        if(ans.length())
        {
            return ans;
        }

        return "-1";
    }
};
