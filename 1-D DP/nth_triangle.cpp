#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int dp[n + 1];
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i - 1] + i;
    }
    cout << dp[n] <<endl;
}