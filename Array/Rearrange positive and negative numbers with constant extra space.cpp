/*

Given an array of positive and negative numbers, arrange them such that all negative integers appear before all the positive integers in the array.

Examples:  

Input:  [12 11 -13 -5 6 -7 5 -3 -6]
Output: [-13 -5 -7 -3 -6 12 11 6 5]

*/

#include <bits/stdc++.h>
using namespace std;

// Merges two subarrays of arr[].
void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid-low+1;
    int n2 = high-mid;

    int L[n1], H[n2];

    for(i=0 ; i<n1 ; i++)
    {
        L[i] = arr[low+i];
    }

    for(j=0; j<n2 ; j++)
    {
        H[j] = arr[mid+j+1];
    }

    i=0;
    j=0;
    k=low;

    while(i<n1 && L[i]<0)
    {
        arr[k++] = L[i++];
    }

    while(j<n2 && H[j]<0)
    {
        arr[k++] = H[j++];
    }

    while(i<n1)
    {
        arr[k++] = L[i++];
    }

    while(j<n2)
    {
        arr[k++] = H[j++];
    }
}

// Function to Rearrange positive and negative numbers in a array
void rearrange(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = low + (high-low)/2;

        rearrange(arr,low,mid);
        rearrange(arr,mid+1,high);
        merge(arr, low, mid, high);
    }
}

/* Function to print an array */
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

/* Driver program to test above functions */
int main()
{
    int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6 };
    int size = sizeof(arr) / sizeof(arr[0]);
 
    rearrange(arr, 0, size - 1);
    printArray(arr, size);
 
    return 0;
}
