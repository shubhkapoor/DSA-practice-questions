/*       Excel Sheet

Given a positive integer N, return its corresponding column title as it would appear in an Excel sheet.
For N =1 we have column A, for 27 we have AA and so on.

Note: The alphabets are all in uppercase.

Example 1:

Input:
N = 51
Output: AY

*/

class Solution
{
public:
    string ExcelColumn(int n)
    {
        // Your code goes here

        string ans = "";

        while(n)
        {
            char ch = 'A' + (n-1)%26;
            ans = ch+ans;
            n = (n-1)/26;
        }

        return ans;
    }
};
