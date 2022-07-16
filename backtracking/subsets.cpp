#include<bits/stdc++.h>
using namespace std;

// O(N*  2 ^ N) O(n* 2 ^ n)
void generateSubsets(string s, vector<string> &subsets){
    for(char ch : s){
        int n = subsets.size();
        for(int i = 0; i < n; i++){
            subsets.push_back(subsets[i] + ch);
        }
    }
}
// O(N* 2 ^ N) O(n)
void backtrackingSubsets(char *input, char *output, int i, int j, vector<string> &subsets){
    if(input[i]== '\0'){
        output[j] = '\0';
        subsets.push_back(output);
        return;
    }
    output[j] = input[i];
    backtrackingSubsets(input, output, i + 1, j + 1, subsets);
    backtrackingSubsets(input, output, i + 1, j, subsets);
}

int main(){
    char input[100];
    char output[100];
    cin >> input;
    vector<string> subsets ={""};
    // generateSubsets(input, subsets);
    backtrackingSubsets(input, output, 0, 0, subsets);
    for(string subset : subsets)
        cout << subset <<" -- ";
    
    cout << endl;
}
/*
Input:  abc
    i = 0  j = 0
    i = 0   a   ''
    i = 1   ab   'a'   'b' ''
    i = 2   abc ab  'ac' 'a' 'bc' 'b''c' ''

*/