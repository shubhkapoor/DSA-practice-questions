/*   Median of Two sorted arrays

Given two sorted arrays of sizes N and M respectively. The task is to find the median of the two arrays when they get merged.
If there are even number of elements in the resulting array, find the floor of the average of two medians.

problem link- https://practice.geeksforgeeks.org/problems/median-of-two-sorted-arrays1618/1/?track=dsa-workshop-1-search-sort&batchId=308

*/

class Solution
{
public:
    //Function to find the median of the two arrays when they get merged.
    int findMedian(int arr[], int n, int brr[], int m)
    {
        // code here

        int begin=0, end=n;

        while(begin<=end)
        {
            int i1 = (begin+end)/2;
            int i2 = (n+m+1)/2 - i1;

            int l1,l2,r1,r2;

            if(i1==0)
            {
                l1 = INT_MIN;
            }
            else
            {
                l1 = arr[i1-1];
            }

            if(i2==0)
            {
                l2 = INT_MIN;
            }
            else
            {
                l2 = brr[i2-1];
            }

            if(i1==n)
            {
                r1 = INT_MAX;
            }
            else
            {
                r1 = arr[i1];
            }

            if(i2==m)
            {
                r2 = INT_MAX;
            }
            else
            {
                r2 = brr[i2];
            }

            if(l1<=r2 && l2<=r1)
            {
                if((n+m)%2 == 0)
                {
                    return (double)(max(l1,l2) + min(r1,r2))/2;
                }
                return (double)max(l1,l2);
            }

            if(l1>r2)
            {
                end = i1-1;
            }

            if(l2>r1)
            {
                begin = i1+1;
            }
        }

        return 0;
    }
};
