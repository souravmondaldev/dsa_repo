#include<bits/stdc++.h>
using namespace std;
// 1210
// 
bool validAutoBioNumber(int n){
    int count[9] = {0};
    int N = n;
    string num = to_string(n);
    for(int num_c : num){
        count[num_c - '0']++;
    }
    int len = num.length();
    for(int i = 0; i < len; i ++){
        if(num[i] - '0' != count[i])
            return false;
    }
    return true;
}
void printAutoBioNumbers(int n){
    int low , high, flag = 0;
    low = pow(10, n - 1);
    high = pow(10, n) - 1;
    for(int num =  low; num <= high; num ++){
        if(validAutoBioNumber(num)){
            cout << num << " ";
            flag = 1;
        }
    }

    if(!flag){
        cout << "No number exist";
    }
    return;
}
int main(){
    int n;
    cin >> n;
    printAutoBioNumbers(n);
    // cout << validAutoBioNumber(1210)<<endl;
}