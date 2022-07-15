#include<bits/stdc++.h>
using namespace std;

// 4 * N board with 4 *1 tile either horizontal or vertical, find 
// the number of ways to tile the board.
/*
________________________________
|  |                            |
|  |   or horizontal            |
|  |                           `|
|  |____________________________|

*/
int waysToPlaceTile(int n){
    if(n <= 3)
        return 1;
    return waysToPlaceTile(n - 1) + waysToPlaceTile(n - 4);
}
int main(){
    int n;
    cin >> n;
    cout << waysToPlaceTile(n)<<endl;

}