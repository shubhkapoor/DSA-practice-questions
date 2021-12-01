/*      Top K Frequent Elements in Array 

Given a non-empty array of integers, find the top k elements which have the highest frequency in the array. If two numbers have the same frequency then the larger number should
be given preference. 

Example 1:

Input:
nums = {1,1,1,2,2,3},
k = 2
Output: {1, 2}


Example 2:

Input:
nums = {1,1,2,2,3,3,3,4},
k = 2
Output: {3, 2}
Explanation: Elements 1 and 2 have the
same frequency ie. 2. Therefore, in this
case, the answer includes the element 2
as 2 > 1.

*/

class Solution
{
public:

    static bool comp(pair<int,int> &a, pair<int,int> &b)
    {
        if(a.first==b.first)
        {
            return a.second > b.second;
        }

        return a.first>b.first;
    }

    vector<int> topK(vector<int>& nums, int k)
    {
        // Code here

        unordered_map<int,int> mp;
        vector<int> ans;
        vector<pair<int,int>> v;

        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
        }

        for(auto it:mp)
        {
            v.push_back({it.second, it.first});
        }

        sort(v.begin(), v.end(),comp);

        int i=0;

        while(k--)
        {
            ans.push_back(v[i].second);
            i++;
        }

        return ans;
    }
};
