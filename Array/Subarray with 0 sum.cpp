/*

Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6
Output: 
Yes
Explanation: 
2, -3, 1 is the subarray with sum 0.


Example 2:

Input:
5
4 2 0 1 6
Output: 
Yes
Explanation: 
0 is one of the element in the array so there exist a subarray with sum 0.

*/

class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        
        int flag = 0;
        int sum = 0;
        unordered_map<int,int> mp;
        
        for(int i=0 ; i<n ; i++)
        {
            sum += arr[i];
            
            if(sum==0 || mp[sum] || arr[i]==0)
            {
                flag = 1;
                break;
            }
            
            mp[sum] = 1;
        }
        
        return flag;
    }
};
