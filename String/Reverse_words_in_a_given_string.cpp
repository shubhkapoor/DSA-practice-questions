/*     Reverse words in a given string

Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i


Example 2:

Input:
S = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole
string , the input string becomes
mno.pqr

*/

class Solution
{
public:
    //Function to reverse words in a given string.
    string reverseWords(string S)
    {
        // code here

        vector<string> v;
        int n = S.size();
        int i=0;

        while(i<n)
        {
            string str="";

            while(S[i]!='.' && i<n)
            {
                str += S[i];
                i++;
            }
            v.push_back(str);
            i++;
        }

        string ans="";

        for(int i=v.size()-1; i>=0; i--)
        {
            ans += v[i];
            ans += '.';
        }

        ans.pop_back();

        return ans;
    }
};
