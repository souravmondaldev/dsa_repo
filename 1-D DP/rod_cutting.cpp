#include<bits/stdc++.h>
using namespace std;

// 8
//1 3 4 5 7 9 10 11
// O(N^2) O(N)
int rodCutting(int n, vector<int> &prices, vector<int> &memo){
    int ans = 0;
    if(n == 0) return ans;
    if(memo[n] != -1) return memo[n];
    for(int i = 1; i <= n; i ++){
        ans = max(ans, rodCutting(n-i, prices, memo) + prices[i]);
    }
    return memo[n]= ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> cuts(n + 1);
    vector<int> memo(n + 1, -1);
    for(int i = 1; i <= n; i++){
        cin >> cuts[i];
    }
    cout<< rodCutting(n, cuts, memo)<<endl;
}