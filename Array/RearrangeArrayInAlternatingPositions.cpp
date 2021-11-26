/*    Rearrange array in alternating positive & negative items with O(1) extra space

Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive number is followed by negative and vice-versa maintaining the order of appearance. 
Number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the end of the array. If there are more negative numbers, they too appear in the end of the array.

problem link- https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/

*/

void rotate(int arr[], int start, int end)
{
    int temp = arr[end];

    for(int i=end-1; i>=start; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[start] = temp;
}

void rearrange(int arr[], int n)
{
    int i=0, j=0, k=0;

    while(i<n && j<n && k<n)
    {
        if(k%2==0)
        {
            if(arr[k]<0)
            {
                k++;
            }
            else
            {
                i=k, j=k;

                while(i<n && arr[i]>=0)
                {
                    i++;
                }
                if(i>=n)
                {
                    break;
                }
                rotate(arr,j,i);
            }
        }
        else
        {
            if(arr[k]>=0)
            {
                k++;
            }
            else
            {
                i=k, j=k;

                while(i<n && arr[i]<0)
                {
                    i++;
                }
                if(i>=n)
                {
                    break;
                }
                rotate(arr,j,i);
            }
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, n);

    rearrange(arr, n);

    cout << "Rearranged array is \n";
    printArray(arr, n);

    return 0;
}
