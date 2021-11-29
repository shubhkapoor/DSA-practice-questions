/*       Non Repeating Numbers

Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two 
numbers.

Example 1:

Input: 
N = 2
arr[] = {1, 2, 3, 2, 1, 4}
Output:
3 4 
Explanation:
3 and 4 occur exactly once.


Example 2:

Input:
N = 1
arr[] = {2, 1, 3, 2}
Output:
1 3
Explanation:
1 3 occur exactly once.

*/

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        // Code here.

        vector<int> ans;
        int size = nums.size();
        int n=0;

        for(int i=0; i<size; i++)
        {
            n = n^nums[i];
        }

        int i=0;

        //  find rightmost set bit
        while(n>0)
        {
            if(n%2==1)
            {
                break;
            }

            n = n/2;
            i++;
        }

        int a=0, b=0;

        for(int j=0; j<size; j++)
        {
            if((nums[j]>>i) & 1)
            {
                a = a^nums[j];
            }
            else
            {
                b = b^nums[j];
            }
        }

        ans.push_back(a);
        ans.push_back(b);

        sort(ans.begin(),ans.end());

        return ans;
    }
};
