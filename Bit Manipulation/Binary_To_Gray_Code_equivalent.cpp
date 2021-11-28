/*     Binary To Gray Code equivalent

You are given a decimal number N. You need to find the gray code of the number N and convert it into decimal.
To see how it's done, refer here.

Example 1:

Input: N = 7
Output: 4
Explanation: 7 is represented as 111 in 
binary form. The gray code of 111 is 100, 
in the binary form whose decimal equivalent 
is 4.


Example 2:

Input: N = 10
Output: 15
Explanation: 10 is represented as 1010 in 
binary form. The gray code of 1010 is 1111, 
in the binary form whose decimal equivalent 
is 15.

*/

class Solution
{
public:
    //  Function to find the gray code of given number n
    int greyConverter(int n)
    {

        // Your code here
        return n^(n>>1);
    }
};
