/*   Palindromic Array

Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. Which will return 1 if all the elements of the Array are palindrome otherwise it will return 0.

problem link- https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1

*/

bool isPalin(int x)
{
    int temp = x;
    int sum=0;
    while(temp!=0)
    {
        int r = temp%10;
        sum = sum*10 + r;
        temp/=10;
    }

    if(sum==x)
        return 1;
    return 0;
}

int PalinArray(int a[], int n)
{
    int count=0;

    for(int i=0; i<n; i++)
    {
        if(isPalin(a[i]))
        {
            count++;
        }
    }

    if(count==n)
        return 1;
    return 0;
}
