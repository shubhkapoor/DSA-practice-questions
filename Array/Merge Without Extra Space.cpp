/*

Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in 
non-decreasing order without using any extra space.

Example 1:

Input:
N = 4, M = 5
arr1[] = {1, 3, 5, 7}
arr2[] = {0, 2, 6, 8, 9}
Output: 0 1 2 3 5 6 7 8 9
Explanation: Since you can't use any extra space, modify the given arrays to form 
arr1[] = {0, 1, 2, 3}
arr2[] = {5, 6, 7, 8, 9}


Example 2:

Input:
N = 2, M = 3
arr1[] = {10, 12}
arr2[] = {5, 18, 20}
Output: 5 10 12 18 20
Explanation: Since you can't use any extra space, modify the given arrays to form 
arr1[] = {5, 10}
arr2[] = {12, 18, 20}

*/

class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    
	    int i=0, k=n-1, j=0;
	    
	    while(i<n && j<m)
	    {
	        if(arr1[i] > arr2[j])
	        {
	            swap(arr1[k--] , arr2[j++]);
	        }
	        else
	        {
	            i++;
	        }
	    }
	    
	    sort(arr1,arr1+n);
	    sort(arr2,arr2+m);
	}
};
