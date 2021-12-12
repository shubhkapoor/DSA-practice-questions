/*        Reverse a string using Stack

You are given a string S, the task is to reverse the string using stack.

Example 1:

Input: S="GeeksforGeeks"
Output: skeeGrofskeeG

*/

char* reverse(char *S, int len)
{
    //code here

    stack<char> st;

    for(int i=0; i<len; i++)
    {
        st.push(S[i]);
    }

    for(int i=0; i<len; i++)
    {
        S[i] = st.top();
        st.pop();
    }

    return S;
}
