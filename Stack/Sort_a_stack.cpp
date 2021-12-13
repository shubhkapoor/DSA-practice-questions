/*        Sort a stack 

You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

Example 1:

Input:
push(2)
push(3)
pop()
getMin()
push(1)
getMin()

Output: 3 2 1

Explanation: In the first test case for
query 
push(2)  the stack will be {2}
push(3)  the stack will be {2 3}
pop()    poped element will be 3 the
         stack will be {2}
getMin() min element will be 2 
push(1)  the stack will be {2 1}
getMin() min element will be 1

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
