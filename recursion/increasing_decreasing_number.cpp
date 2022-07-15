#include<bits/stdc++.h>
using namespace std;
void print_desc(int n){
    cout << n << " ";
    if(n == 0)
        return;
    print_desc(n - 1);
}
void print_inc(int n){
    if(n == 0)
        return;
    print_inc(n - 1);
    cout << n << " ";
}

int main(){
    int n = 5;
    print_desc(n);
    print_inc(n);
}