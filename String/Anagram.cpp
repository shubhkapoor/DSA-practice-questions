/*     Anagram 

Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is 
another string that contains the same characters, only the order of characters can be different. For example, “act” and “tac” are an anagram of each other.

Example 1:

Input:
a = geeksforgeeks, b = forgeeksgeeks
Output: YES
Explanation: Both the string have same
characters with same frequency. So, 
both are anagrams.
Example 2:

Input:
a = allergy, b = allergic
Output: NO
Explanation:Characters in both the strings
are not same, so they are not anagrams.

*/

class Solution
{
public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b)
    {
        // Your code here

        int n = a.length();
        int m = b.length();

        if(n!=m)
        {
            return false;
        }

        int count[256] = {0};

        for(int i=0; i<n; i++)
        {
            count[a[i]]++;
            count[b[i]]--;
        }

        for(int i=0; i<256; i++)
        {
            if(count[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
};
