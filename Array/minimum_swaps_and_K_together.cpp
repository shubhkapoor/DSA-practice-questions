/*   Minimum swaps and K together

Given an array arr of n positive integers and a number k. One can apply a swap operation on the array any number of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . Find the minimum number of swaps required to bring all the numbers less than or equal to k together, i.e. make them a contiguous subarray.

problem link- https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

*/

class Solution
{
public:
    int minSwap(int a[], int n, int k)
    {

        int goodVal=0, badVal=0;

        for(int i=0; i<n; i++)
        {
            if(a[i]<=k)
            {
                goodVal++;
            }
        }

        for(int i=0; i<goodVal; i++)
        {
            if(a[i]>k)
            {
                badVal++;
            }
        }

        int i=0, j=goodVal;
        int ans=badVal;

        while(j<n)
        {
            if(a[i]>k)
            {
                badVal--;
            }

            if(a[j]>k)
            {
                badVal++;
            }

            i++;
            j++;

            ans = min(ans,badVal);
        }

        return ans;
    }
};
