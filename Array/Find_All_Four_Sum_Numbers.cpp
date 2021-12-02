/*        Find All Four Sum Numbers

Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.

Example 1:

Input:
N = 5, K = 3
A[] = {0,0,2,1,1}
Output: 0 0 1 2 $
Explanation: Sum of 0, 0, 1, 2 is equal
to K.

Example 2:

Input:
N = 7, K = 23
A[] = {10,2,3,4,5,7,8}
Output: 2 3 8 10 $2 4 7 10 $3 5 7 8 $
Explanation: Sum of 2, 3, 8, 10 = 23,
sum of 2, 4, 7, 10 = 23 and sum of 3,
5, 7, 8 = 23.

*/

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k)
    {
        // Your code goes here
        int n = arr.size();
        sort(arr.begin(),arr.end());

        vector<vector<int>> ans;

        set<vector<int>> s;

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int start = j+1;
                int end = n-1;

                while(start<end)
                {
                    int sum = arr[i] + arr[j] + arr[start] + arr[end];

                    if(sum==k)
                    {
                        s.insert({arr[i], arr[j], arr[start], arr[end]});
                        start++;
                        end--;
                    }
                    else if(sum>k)
                    {
                        end--;
                    }
                    else
                    {
                        start++;
                    }
                }
            }
        }

        for(auto it : s)
        {
            ans.push_back(it);
        }

        return ans;
    }
};
