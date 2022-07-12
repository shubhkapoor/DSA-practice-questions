/*

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2

Example 2:

Input: nums = [3,1,3,4,2]
Output: 3

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            nums[nums[i]%n] = nums[nums[i]%n] + n;
        }
        
        for(int j=0;j<n;j++)
        {
            if(nums[j]/n > 1)
            {
                return j;
            }
        }
        
        return -1;
    }
};
