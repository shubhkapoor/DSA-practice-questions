/*

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array
are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted
container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]

*/

class Solution
{
public:
    void nextPermutation(vector<int>& arr)
    {
        int idx = -1;
        int n = arr.size();

        for(int i=n-1 ; i>0 ; i--)
        {
            if(arr[i] > arr[i-1])
            {
                idx = i;
                break;
            }
        }

        if(idx == -1)
        {
            reverse(arr.begin(), arr.end());
        }
        else
        {
            int prev = idx;

            for(int i=idx+1 ; i<n ; i++)
            {
                if(arr[i] > arr[idx-1] && arr[i] < arr[prev])
                {
                    prev = i;
                }
            }

            swap(arr[idx-1], arr[prev]);
            sort(arr.begin()+idx, arr.end());
        }
    }
};
