#include <bits/stdc++.h>
using namespace std;

int minimumWork(int arr[], int n, int dp[])
{
    dp[0] = arr[0];
    dp[1] = arr[1];
    dp[2] = arr[2];
    for (int i = 3; i < n; i++)
    {
        dp[i] = min(dp[i - 1], min(dp[i - 2], dp[i - 3])) + arr[i];
    }
    return min(dp[n - 1], min(dp[n - 2], dp[n - 3]));
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minimumWork(arr, n, dp) << endl;
}