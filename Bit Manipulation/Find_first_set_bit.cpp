/*     Find first set bit

Given an integer an N. The task is to return the position of first set bit found from the right side in the binary representation of the number.
Note: If there is no set bit in the integer N, then return 0 from the function.  

Example 1:

Input: N = 18
Output: 2
Explanation: Binary representation of 
18 is 010010,the first set bit from the 
right side is at position 2.


Example 2:

Input: N = 12 
Output: 3 
Explanation: Binary representation 
of  12 is 1100, the first set bit 
from the right side is at position 3.

*/

class Solution
{
public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here

        if(n==0)
        {
            return 0;
        }

        int index=1;

        while(n)
        {
            if((n&1)==1)
            {
                return index;
            }
            index++;
            n = n>>1;
        }
    }
};
