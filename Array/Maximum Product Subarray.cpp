/*

Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Example 1:

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product is [6, -3, -10] which gives product as 180.

Example 2:

Input:
N = 6
Arr[] = {2, 3, 4, 5, -1, 0}
Output: 120
Explanation: Subarray with maximum product is [2, 3, 4, 5] which gives product as 120.

*/

class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    
	    long long start=1, end=1;
	    long long ans = INT_MIN;
	    
	    int i=0, j=n-1;
	    
	    while(i<n && j>=0)
	    {
	        start *= arr[i];
	        end *= arr[j];
	        
	        ans = max(ans , max(start,end));
	        
	        if(arr[i] == 0)
	        {
	            start = 1;
	        }
	        
	        if(arr[j] == 0)
	        {
	            end = 1;
	        }
	        
	        i++;
	        j--;
	    }
	    
	    return ans;
	}
};
