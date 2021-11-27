/*      Isomorphic Strings 

Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
Note: All occurrences of every character in ‘str1’ should map to the same character in ‘str2’

Example 1:

Input:
str1 = aab
str2 = xxy
Output: 1
Explanation: There are two different
charactersin aab and xxy, i.e a and b
with frequency 2and 1 respectively.
Example 2:

Input:
str1 = aab
str2 = xyz
Output: 0
Explanation: There are two different
charactersin aab but there are three
different charactersin xyz. So there
won't be one to one mapping between
str1 and str2.

*/

class Solution
{
public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {

        // Your code here

        int n=str1.length();
        int m=str2.length();

        if(n!=m)
        {
            return false;
        }

        int m1[256]= {0};
        int m2[256]= {0};

        for(int i=0; i<n; i++)
        {
            if(!m1[str1[i]] && !m2[str2[i]])
            {
                m1[str1[i]] = str2[i];
                m2[str2[i]] = str1[i];
            }
            else if(m1[str1[i]] != str2[i])
            {
                return false;
            }
        }

        return true;
    }
};
