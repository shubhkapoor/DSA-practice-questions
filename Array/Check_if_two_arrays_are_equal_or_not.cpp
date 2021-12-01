/*       Check if two arrays are equal or not

Given two arrays A and B of equal size N, the task is to find if given arrays are equal or not. Two arrays are said to be equal if both of them contain same set of elements,
arrangements (or permutation) of elements may be different though.
Note : If there are repetitions, then counts of repeated elements must also be same for two array to be equal.

Example 1:

Input:
N = 5
A[] = {1,2,5,4,0}
B[] = {2,4,5,0,1}
Output: 1
Explanation: Both the array can be 
rearranged to {0,1,2,4,5}


Example 2:

Input:
N = 3
A[] = {1,2,5}
B[] = {2,4,15}
Output: 0
Explanation: A[] and B[] have only 
one common value.

*/

class Solution
{
public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N)
    {
        //code here

        unordered_map<int,int> mp;

        for(int i=0; i<N; i++)
        {
            mp[A[i]]++;
            mp[B[i]]--;
        }

        for(auto it : mp)
        {
            if(it.second!=0)
            {
                return 0;
            }
        }

        return 1;
    }
};
