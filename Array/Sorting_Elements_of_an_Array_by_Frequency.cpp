/*         Sorting Elements of an Array by Frequency

Given an array of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. If frequencies of two elements are same,
then smaller number comes first.

Example 1:

Input:
N = 5
A[] = {5,5,4,6,4}
Output: 4 4 5 5 6
Explanation: The highest frequency here is
2. Both 5 and 4 have that frequency. Now
since the frequencies are same then 
smallerelement comes first. So 4 4 comes 
firstthen comes 5 5. Finally comes 6.
The output is 4 4 5 5 6.


Example 2:

Input:
N = 5
A[] = {9,9,9,2,5}
Output: 9 9 9 2 5
Explanation: The highest frequency here is
3. The element 9 has the highest frequency
So 9 9 9 comes first. Now both 2 and 5
have same frequency. So we print smaller
element first.
The output is 9 9 9 2 5.

*/

class Solution
{
public:
    //Complete this function
    //Function to sort the array according to frequency of elements.

    static bool comparator(pair<int,int> &a, pair<int,int> &b)
    {
        if(a.first==b.first)
        {
            return a.second<=b.second;
        }

        return a.first>b.first;
    }

    vector<int> sortByFreq(int arr[],int n)
    {
        //Your code here

        unordered_map<int,int> mp;
        vector<pair<int,int>> vec;
        vector<int> ans;

        for(int i=0; i<n; i++)
        {
            mp[arr[i]]++;
        }

        for(auto it:mp)
        {
            vec.push_back({it.second, it.first});
        }

        sort(vec.begin(),vec.end(),comparator);

        for(int i=0; i<vec.size(); i++)
        {
            while(vec[i].first!=0)
            {
                ans.push_back(vec[i].second);
                vec[i].first--;
            }
        }

        return ans;
    }
};
