/*     Rightmost different bit

Given two numbers M and N. The task is to find the position of the rightmost different bit in the binary representation of numbers.

Example 1: 

Input: M = 11, N = 9
Output: 2
Explanation: Binary representation of the given 
numbers are: 1011 and 1001, 
2nd bit from right is different.


Example 2:

Input: M = 52, N = 4
Output: 5
Explanation: Binary representation of the given 
numbers are: 110100 and 0100, 
5th-bit from right is different.

*/

class Solution
{
public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here

        int x = m^n;
        int pos=1;

        while(x>0)
        {
            if((x&1)==1)
            {
                return pos;
            }
            x = x>>1;
            pos++;
        }
    }
};
