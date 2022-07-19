#include<bits/stdc++.h>
using namespace std;
int minStepsToOne(int n, vector<int>& memo){
    // base case
    if(n == 1) return memo[n] = 0;
    int ans = INT_MAX;
    if(memo[n] != -1) return memo[n];
    if(n % 2 == 0)
     ans = min(ans, minStepsToOne(n/2, memo) + 1);
    if(n % 3 == 0)
        ans = min(ans, minStepsToOne(n/3, memo) + 1);
    ans = min(ans, minStepsToOne(n-1, memo) + 1);
    return memo[n] = ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> memo(n+1, -1);
    cout << minStepsToOne(n, memo) << endl;
}