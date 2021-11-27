/*    Maximum profit by buying and selling a share at most twice

In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, whereas the second 
transaction can only start after the first one is complete (Buy->sell->Buy->sell). Given stock prices throughout the day, find out the maximum profit that a share trader could 
have made.

problem link- https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/

*/

int maxProfit(int arr[],int n)
{
    int buy1 = INT_MIN;
    int sell1 = 0;
    int buy2 = INT_MIN;
    int sell2 = 0;

    for(int i=0; i<n; i++)
    {
        buy1 = max(buy1,-arr[i]);
        sell1 = max(sell1,buy1+arr[i]);
        buy2 = max(buy2,sell1-arr[i]);
        sell2 = max(sell2,buy2+arr[i]);
    }
    return sell2;
}

int main()
{
    int arr[] = {10, 22, 5, 75, 65, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxProfit(arr,n);
    return 0;
}
