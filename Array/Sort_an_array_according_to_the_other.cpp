/*       Sort an array according to the other

Given two integer arrays A1[ ] and A2[ ] of size N and M respectively. Sort the first array A1[ ] such that all the relative positions of the elements in the first array 
are the same as the elements in the second array A2[ ].
See example for better understanding.
Note: If elements are repeated in the second array, consider their first occurance only.

Example 1:

Input:
N = 11 
M = 4
A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
A2[] = {2, 1, 8, 3}
Output: 
2 2 1 1 8 8 3 5 6 7 9
Explanation: Array elements of A1[] are
sorted according to A2[]. So 2 comes first
then 1 comes, then comes 8, then finally 3
comes, now we append remaining elements in
sorted order.


Example 2:

Input:
N = 11 
M = 4
A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
A2[] = {99, 22, 444, 56}
Output: 
1 1 2 2 3 5 6 7 8 8 9
Explanation: No A1[] elements are in A2[]
so we cannot sort A1[] according to A2[].
Hence we sort the elements in non-decreasing 
order.

*/

class Solution
{
public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]

    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> a1, int n, vector<int> a2, int m)
    {
        //Your code here

        map<int,int> mp;
        vector<int> ans;

        for(auto it : a1)
        {
            mp[it]++;
        }

        for(auto x : a2)
        {
            if(mp.find(x) != mp.end())
            {
                int count = mp[x];
                vector<int>v(count,x);

                ans.insert(ans.end(), v.begin(), v.end());

                mp.erase(x);
            }
        }

        for(auto x : mp)
        {
            int val = x.first;
            int count = x.second;

            vector<int>v(count,val);

            ans.insert(ans.end(), v.begin(), v.end());
        }

        return ans;
    }
};
