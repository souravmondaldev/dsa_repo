#include<bits/stdc++.h>
using namespace std;

int numberOfWays(int n){
    if(n <= 1)
        return 1;
    if(n == 2)
        return 2;
    return numberOfWays(n - 1) + (n - 1) * numberOfWays(n - 2);
} 
//possible n friend going to party alone or somaone else
int main(){
    int n;
    cin >> n;
    cout << numberOfWays(n);
}