/*     Check if strings are rotations of each other or not

Given two strings s1 and s2. The task is to check if s2 is a rotated version of the string s1. The characters in the strings are in lowercase.


Example 1:

Input:
geeksforgeeks
forgeeksgeeks
Output: 
1
Explanation: s1 is geeksforgeeks, s2 is
forgeeksgeeks. Clearly, s2 is a rotated
version of s1 as s2 can be obtained by
left-rotating s1 by 5 units.
 

Example 2:

Input:
mightandmagic
andmagicmigth
Output: 
0
Explanation: Here with any amount of
rotation s2 can't be obtained by s1.

*/

class Solution
{
public:
    bool areRotations(string s1,string s2)
    {
        // Your code here

        if(s1.size()!=s2.size())
        {
            return false;
        }

        int n= s1.size();

        s1 = s1+s1;

        int i= 0, j=s2.size()-1;

        while(j<s1.size())
        {
            if(s1.substr(i,j-i+1)==s2)
            {
                return true;
            }
            i++;
            j++;
        }

        return false;
    }
};
