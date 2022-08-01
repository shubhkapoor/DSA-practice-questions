/*

Given an integer N, find its factorial.

Example 1:

Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120

Example 2:

Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

*/

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        
        vector<int> ans;
        ans.push_back(1);
        
        int sum = 0;
        int carry = 0;
        
        for(int i=2 ; i<=N ; i++)
        {
            sum = 0;
            
            for(int j=ans.size()-1 ; j>=0 ; j--)
            {
                sum = ans[j]*i + carry;
                ans[j] = sum%10;
                carry = sum/10;
            }
            
            while(carry!=0)
            {
                ans.insert(ans.begin() , carry%10);
                carry /= 10;
            }
        }
        
        return ans;
    }
};
