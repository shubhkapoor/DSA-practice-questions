/*     Power of 2 

Given a non-negative integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2x for some x.
 
Example 1:

Input: N = 1
Output: true
Explanation:
1 is equal to 2 raised to 0 (20 = 1).


Example 2:

Input: N = 98
Output: false
Explanation: 
98 cannot be obtained by any power of 2.

*/

class Solution
{
public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n)
    {
        // Your code here

        if(n==0)
        {
            return false;
        }

        //  changing the rightmost set bit to unset bit n&(n-1)we see if it is equal to 0.
        return (!(n&(n-1)));
    }
};
