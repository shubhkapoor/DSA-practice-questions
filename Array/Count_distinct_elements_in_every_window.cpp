/*      Count distinct elements in every window

Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

Example 1:

Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
Explanation: Window 1 of size k = 4 is
1 2 1 3. Number of distinct elements in
this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number
of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number
of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number
of distinct elements in this window are 3.


Example 2:

Input:
N = 3, K = 2
A[] = {4,1,1}
Output: 2 1

*/

class Solution
{
public:
    vector <int> countDistinct (int arr[], int n, int k)
    {
        //code here.

        vector<int> ans;

        unordered_map<int,int> mp;

        for(int i=0; i<k; i++)
        {
            mp[arr[i]]++;
        }

        ans.push_back(mp.size());

        for(int i=k; i<n; i++)
        {
            mp[arr[i-k]]--;

            if(mp[arr[i-k]]==0)
            {
                mp.erase(arr[i-k]);
            }

            mp[arr[i]]++;

            ans.push_back(mp.size());
        }

        return ans;
    }
};
