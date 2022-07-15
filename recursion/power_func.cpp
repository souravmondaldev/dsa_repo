#include<bits/stdc++.h>
using namespace std;

int pow(int a, int n){
    if(n == 0)
        return 1;
    return a * pow(a, n - 1);
}
// O(N) O(N)
int main(){
    int n = 10, a = 2;
    cout << pow(a, n);
}