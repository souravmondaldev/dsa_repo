#include<bits/stdc++.h>
using namespace std;

// all possible binary string of length n without consecutive 1's

// f(N) = f(N-1) + f(N-2) reason divided F(N-1) with starting 0 and
// f(n - 1) with staring 1 which is invalid so this one divided to
// 0 fixed first meaning f(n - 2) ways
// base case n = 0 f(n) = 1 as 0
//  n = 1  f(n) = 2  as  0, 1
// n = 2 f(n) = 3  which f(1) + f(0)  001, 010, 100
// O(2 ^ N) O(n)
int possibleBinaryString(int n){
    if(n <= 1)
        return n + 1;
    return possibleBinaryString(n - 1) + possibleBinaryString(n - 2);
}
int main(){
    int n;
    cin >> n;
    cout << possibleBinaryString(n);
}
// dp to o(N)
// matrix exponensiation to O(K^3 LogN) where K is number of terms 
// f is depending here f(n) = f(n-1) + f(n-2) thus k = 2,time O(8logN)