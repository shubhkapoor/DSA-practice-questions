/*

Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Example 1:
Input:
N = 4
mat[][] =     {{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }}
K = 3
Output: 27
Explanation: 27 is the 3rd smallest element.
 

Example 2:
Input:
N = 4
mat[][] =     {{10, 20, 30, 40}
                   {15, 25, 35, 45}
                   {24, 29, 37, 48}
                   {32, 33, 39, 50}}
K = 7
Output: 30
Explanation: 30 is the 7th smallest element.

*/

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    //Your code here
    
    int startVal = mat[0][0];
    int endVal = mat[n-1][n-1];
    int midVal;
    
    while(startVal<=endVal)
    {
        midVal = (startVal + endVal)/2;
        int count=0;
        
        for(int i=0 ; i<n ; i++)
        {
            int low=0 , high=n-1;
            
            while(low<=high)
            {
                int mid = low + (high-low)/2;
                
                if(mat[i][mid] <= midVal)
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
            
            count += low;
        }
        
        if(count < k)
        {
            startVal = midVal+1;
        }
        else
        {
            endVal = midVal-1;
        }
    }
    
    return startVal;
}
