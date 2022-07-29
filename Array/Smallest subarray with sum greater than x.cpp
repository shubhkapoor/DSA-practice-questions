/*

Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.
Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).

Example 1:

Input:
A[] = {1, 4, 45, 6, 0, 19}
x  =  51
Output: 3
Explanation:
Minimum length subarray is {4, 45, 6}

Example 2:
Input:
A[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Explanation:
Minimum length subarray is {10}

*/

class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        
        int ans = INT_MAX;
        int sum = 0;
        int i=0, j=0;
        
        while(i<=j && j<n)
        {
            while(sum<=x && j<n)
            {
                sum += arr[j];
                j++;
            }
            
            while(sum>x && i<j)
            {
                ans = min(ans , j-i);
                sum -= arr[i];
                i++;
            }
        }
        
        return ans;
    }
};
