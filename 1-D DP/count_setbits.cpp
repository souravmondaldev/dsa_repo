#include<bits/stdc++.h>
using namespace std;
// O(nlogn)
int countSetBits(int n){
    int count = 0;
    while(n){
        count += n & 1;
        n = n >> 1;
    }
    return count;
}
// dp O(N)
int main(){
    int n;
    cin >> n;
    int dp[n + 1];
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        cout << "setbit count of "<< i << " is "<<countSetBits(i)<<endl;
        dp[i] = dp[i / 2] + (i & 1);
        cout << dp[i]   << endl;
    }
}