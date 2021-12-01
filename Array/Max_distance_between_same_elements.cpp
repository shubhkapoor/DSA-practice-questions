/*        Max distance between same elements

Given an array with repeated elements, the task is to find the maximum distance between two occurrences of an element.

Example 1:

Input
n= 6
arr = {1, 1, 2, 2, 2, 1}

Output
5

Explanation
arr[] = {1, 1, 2, 2, 2, 1}
Max Distance: 5
Distance for 1 is: 5-0 = 5
Distance for 2 is : 4-2 = 2
Max Distance 5


Example 2:

Input
n = 12
arr = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2}

Output
10

Explanation

arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2}
Max Distance 10
maximum distance for 2 is 11-1 = 10
maximum distance for 1 is 4-2 = 2
maximum distance for 4 is 10-5 = 5

*/

class Solution
{
public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
        //Code here

        unordered_map<int,int> mp;
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            auto it = mp.find(arr[i]);

            if(it!=mp.end())
            {
                int idx = (*it).second;

                ans = max(ans, i-idx);
            }
            else
            {
                mp.insert({arr[i],i});
            }
        }

        return ans;
    }
};
