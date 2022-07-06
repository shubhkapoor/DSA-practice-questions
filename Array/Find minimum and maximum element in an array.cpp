/*

Given an array A of size N of integers. Your task is to find the minimum and maximum elements in the array.

Example 1:

Input:
N = 6
A[] = {3, 2, 1, 56, 10000, 167}
Output:
min = 1, max =  10000
 

Example 2:

Input:
N = 5
A[]  = {1, 345, 234, 21, 56789}
Output:
min = 1, max = 56789

*/

// User function Template for C

struct pair getMinMax(long long int arr[], long long int n)
{
    struct pair minmax;

    minmax.min = arr[0];
    minmax.max = arr[0];

    for(int i=0 ; i<n ; i++)
    {
        if(arr[i] < minmax.min)
        {
            minmax.min = arr[i];
        }

        if(arr[i] > minmax.max)
        {
            minmax.max = arr[i];
        }
    }

    return minmax;
}
