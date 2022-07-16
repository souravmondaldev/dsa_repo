#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> gr[N];
int vis[N];
bool hamilton_path = false;
// hamiltonian path problem- visit every vertex exactly once
// O(Number of hamiltonian paths)
void hamiltonPaths(int curr, int cnt , int n){
    if(cnt == n){
        hamilton_path = true;
        return;
    }
    vis[curr] = 1;
    for(auto it : gr[curr]){
        if(!vis[it])
            hamiltonPaths(it, cnt + 1 , n);
    }

    vis[curr] = 0;
    return;
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    // bool hamilton_path = false;
    for(int i = 0; i < n; i ++){
        hamiltonPaths(i, 1, n);
    }
    cout << hamilton_path <<endl;
}