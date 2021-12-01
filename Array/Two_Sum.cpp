/*     Two Sum

Given an array of positive integers and an integer. Determine whether or not there exist two elements in A whose sum is exactly equal to that integer.

Example 1:

Input:
N = 6, X = 16
A[] = {1,4,45,6,10,8}
Output: Yes
Explanation: 10 and 6 are numbers
making a pair whose sum is equal to 16.


Example 2:

Input:
N = 5, X = 10
A[] = {1,2,4,3,6}
Output: Yes

*/

class Solution
{
public:
    bool keypair(vector<int> A, int N, int X)
    {
        // Your code goes here

        unordered_set<int> s;

        for(int i=0; i<N; i++)
        {
            int diff = X-A[i];

            if(s.find(diff)!=s.end())
            {
                return true;
            }
            else
            {
                s.insert(A[i]);
            }
        }

        return false;
    }
};
