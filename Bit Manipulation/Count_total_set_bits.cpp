/*     Count total set bits

You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

Example 1:

Input: N = 4
Output: 5
Explanation:
For numbers from 1 to 4.
For 1: 0 0 1 = 1 set bits
For 2: 0 1 0 = 1 set bits
For 3: 0 1 1 = 2 set bits
For 4: 1 0 0 = 1 set bits
Therefore, the total set bits is 5.


Example 2:

Input: N = 17
Output: 35
Explanation: From numbers 1 to 17(both inclusive), 
the total number of set bits is 35.

*/

class Solution
{
public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here

        if(n==0)
        {
            return 0;
        }

        int x=0;

        while(1<<x <= n)
        {
            x++;
        }

        x = x-1;

        // bits upto raise to x :   (2^(x-1))*x
        int b2x = x*(1<<x-1);

        // msb from 2 raise to x to n :   (n- 2^x +1)
        int msb2x = n - (1<<x) +1;

        // remaining bits :   n - 2^x
        int rem = n - (1<<x);

        int ans = b2x + msb2x + countSetBits(rem);

        return ans;
    }
};
