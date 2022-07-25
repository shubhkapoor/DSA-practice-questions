/*

Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between 
the blocks during the rainy season.  

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10

Example 2:

Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above block of height 4 is 3 units and above block of height 0 is 7 units. So, the total unit of water trapped is 10 units.

*/


//Method 1:  T.C-O(N) , S.C- O(N)

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        
        long long ans = 0;
        
        int l[n];
        int r[n];
        
        int i=1, j=n-2;
        
        l[0] = arr[0];
        r[n-1] = arr[n-1];
        
        while(i<n)
        {
            l[i] = max(l[i-1] , arr[i]);
            i++;
        }
        
        while(j>=0)
        {
            r[j] = max(r[j+1] , arr[j]);
            j--;
        }
        
        for(int i=0 ; i<n ; i++)
        {
            ans += min(l[i] , r[i]) - arr[i];
        }
        
        return ans;
    }
};


//Method 2:  T.C: O(N) , S.C: O(1)

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        
        long long ans = 0;
        int i=0;
        int j=n-1;
        
        int max_l = 0;
        int max_r = 0;
        
        while(i<=j)
        {
            if(arr[i] < arr[j])
            {
                if(arr[i] > max_l)
                {
                    max_l = arr[i];
                }
                else
                {
                    ans += max_l - arr[i];
                }
                
                i++;
            }
            else
            {
                if(arr[j] > max_r)
                {
                    max_r = arr[j];
                }
                else
                {
                    ans += max_r - arr[j];
                }
                
                j--;
            }
        }
        
        return ans;
    }
};
