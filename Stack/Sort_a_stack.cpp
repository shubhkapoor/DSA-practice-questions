/*        Sort a stack 

Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1

Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2

*/

void SortedStack :: sort()
{
    //Your code here

    int i=0, j;
    int n = s.size();
    int *a = new int[n];

    while(!s.empty())
    {
        a[i++] = s.top();
        s.pop();
    }

    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        s.push(a[i]);
    }
}
