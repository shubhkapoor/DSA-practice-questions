/*    Longest consecutive subsequence

Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be 
in any order.

problem link- https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

*/

class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        //Your code here

        set<int> s;

        for(int i=0; i<N; i++)
        {
            s.insert(arr[i]);
        }

        int ans=0;

        for(int i=0; i<N; i++)
        {
            if(s.find(arr[i]-1)==s.end())
            {
                int val = arr[i]+1;

                while(s.find(val)!=s.end())
                {
                    val++;
                }

                ans = max(ans,val-arr[i]);
            }
        }
        return ans;
    }
};
