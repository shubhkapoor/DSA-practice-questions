/*

Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 
Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Example 2:

Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.

Example 3:

Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.

*/

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
  
    long long int merge(long long arr[] , long long temp[] , long long int left , long long int mid , long long int right)
    {
        int i = left;
        int j = mid;
        int k = left;
        
        long long int inv_count=0;
        
        while(i<mid && j<=right)
        {
            if(arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = temp[j++];
                inv_count += mid - i;
            }
        }
        
        while(i<mid)
        {
            temp[k++] = arr[i++];
        }
        
        while(j<=right)
        {
            temp[k++] = arr[j++];
        }
        
        for(int i=left ; i<=right ; i++)
        {
            arr[i] = temp[i];
        }
        
        return inv_count;
    }
    
    long long int mergesort(long long arr[] , long long temp[] , long long int left , long long int right)
    {
        long long int mid , inv_count=0;
        
        if(left < right)
        {
            mid = left + (right-left)/2;
            
            inv_count += mergesort(arr , temp , left , mid);
            inv_count += mergesort(arr , temp , mid+1 , right);
            inv_count += merge(arr , temp , left , mid+1 , right);
        }
        
        return inv_count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        
        long long int temp[N];
        long long int inv_count = mergesort(arr , temp , 0 , N-1);
        
        return inv_count;
    }
};
