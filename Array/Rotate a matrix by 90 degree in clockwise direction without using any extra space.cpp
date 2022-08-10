/*

Given a square matrix, turn it by 90 degrees in a clockwise direction without using any extra space.

Examples: 

Input:
1 2 3 
4 5 6
7 8 9  
Output:
7 4 1 
8 5 2
9 6 3

Input:
1 2
3 4
Output:
3 1
4 2 

*/

// Transpose each column  --->  Swap elements in each row

#include <bits/stdc++.h>

using namespace std;

#define N 4

void rotate90Clockwise(int arr[N][N])
{

    for(int i=0 ; i<N ; i++)
    {
        for(int j=i ; j<N ; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    for(int i=0 ; i<N ; i++)
    {
        int left=0 , right=N-1;

        while(left<right)
        {
            int temp = arr[i][left];
            arr[i][left] = arr[i][right];
            arr[i][right] = temp;

            left++;
            right--;
        }
    }
}

void printMatrix(int arr[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}

// Driver code
int main()
{
    int arr[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rotate90Clockwise(arr);
    printMatrix(arr);
    return 0;
}
