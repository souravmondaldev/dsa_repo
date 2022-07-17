#include<bits/stdc++.h>
using namespace std;
int count1 = 0;

int func1(int n){
    if(n <= 1)
        return 1;
    return func1(n - 1) + func1(n - 2);
}
int func2(int idx, int n, bool prev_num){
    count1 ++;
    if(idx == n - 1)
        return 1;
    int ans = 0;
    ans += func2(idx + 1, n, false);
    if(!prev_num)
        ans += func2(idx + 1, n, true);

    return ans;
}
int main(){
    int n; 
    cin >> n;
    cout << func1(n) << endl;
    cout << func2(0, n, false) << endl;
    cout <<"count "<<count1<<endl;
}
