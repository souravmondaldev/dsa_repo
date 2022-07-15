#include<bits/stdc++.h>
using namespace std;


// O(LogN) O(LogN)
int fast_pow(int a , int n){
    if(n == 0)
        return 1;
    int subPow = fast_pow(a, n / 2);
    int squareOfPow = subPow *  subPow;
    if(n & 1)
        return a* squareOfPow;
    return squareOfPow;
}
int main(){
    int a, n;
    cin >>a >> n;
    // A^N == even A^(N/2) * A^(N/2), odd A* A^(N/2) 
    cout << fast_pow(a, n);
}