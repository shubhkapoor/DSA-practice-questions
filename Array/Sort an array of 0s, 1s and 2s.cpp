/*

Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

Example 1:

Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated into ascending order.


Example 2:

Input: 
N = 3
arr[] = {0 1 0}
Output:
0 0 1
Explanation:
0s 1s and 2s are segregated into ascending order.

*/

class Solution
{
public:
    void sort012(int a[], int n)
    {
        // code here

        if(n==1)
        {
            return;
        }

        int low, mid, high;

        low=0;
        mid=0;
        high=n-1;

        while(mid<=high)
        {
            if(a[mid] == 0)
            {
                swap(a[mid],a[low]);
                mid++;
                low++;
            }

            else if(a[mid] == 1)
            {
                mid++;
            }

            else
            {
                swap(a[mid],a[high]);
                high--;
            }
        }
    }
};
