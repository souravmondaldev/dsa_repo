#include<bits/stdc++.h>
using namespace std;

// rules:
// 1. opening braces should be less than n
// 2. closing braces should be always less than equal opening
// O( 4^n / n^1/2)
void generateBrackets(string output, int n, int opening, int closing, int idx){
    if(idx == n * 2){
        cout << output<<endl;
        return;
    }
    // if(opening < n){
    //     generateBrackets(output + '(', n, opening + 1, closing, idx + 1);
    // }
    // if(closing < opening){
    //     generateBrackets(output + ')', n, opening, closing + 1, idx + 1);
    // }
    if(opening < n){
        output += '(';
        generateBrackets(output, n, opening + 1, closing, idx + 1);
        output.pop_back();
    }
    if(closing < opening){
         output += ')';
        generateBrackets(output + ')', n, opening, closing + 1, idx + 1);
        output.pop_back();
    }
}
int main(){
    int n;
    cin >> n;
    string output;
    generateBrackets(output,n, 0, 0 , 0);
}