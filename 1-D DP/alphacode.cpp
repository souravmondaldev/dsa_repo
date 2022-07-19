#include <bits/stdc++.h>
using namespace std;
bool validDigit(int digit)
{
    return digit >= 0 && digit <= 9;
}
bool validAlpha(int n)
{
    return n >= 1 && n <= 26;
}
int alphacode(int idx, string n, vector<int> &dp, string curr)
{
    if (idx == n.length())
    {
        cout << curr << endl;
        return dp[idx] = 1;
    }
    if(dp[idx] != -1) return dp[idx]; // comment this to print all pairs
    int currDigit = n[idx] - '0';
    int ans = 0;
    if (currDigit >= 1 && currDigit <= 9)
    {
        char currChar = currDigit + 'A' - 1;
        ans += alphacode(idx + 1, n, dp, curr + currChar);
    }
    if (idx + 1 < n.length())
    {
        int nextDigit = n[idx + 1] - '0';
        int nextNum = currDigit * 10 + nextDigit;
        if (validAlpha(nextNum))
        {
            char nextChar = nextNum + 'A' - 1;
            ans += alphacode(idx + 2, n, dp, curr + nextChar);
        }
    }
    return dp[idx] = ans;
}
// number of possible ways to decode number to alphabets
// 25114 - 6 ways BEAAD, BEAN ...
int main()
{
    string n;
    cin >> n;
    string curr = "";
    vector<int> dp(n.length() + 1, -1);
    cout << alphacode(0, n, dp, curr) << endl;
    // cout << dp[0]<<endl;
}