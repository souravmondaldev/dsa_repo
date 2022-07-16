#include<bits/stdc++.h>
using namespace std;
void printBoard(int board[][20], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(int board[][20], int n, int row, int col){
    // column
    for(int i = 0; i < row; i++){
        if(board[i][col] == 1)
            return false;
    }
    int i =  row, j = col;
    // left column
    while(i >= 0 and j >= 0){
        if(board[i][j] == 1)
            return false;
        i--;
        j--;
    }
    i =  row, j = col;
    // right column
    while(i >= 0 and j < n){
        if(board[i][j] == 1)
            return false;
        i--;
        j ++;
    }
    return true;
}

int solveNQueen(int n, int board[][20], int i){
    // base case
    // idx become n meaning all queen placed
    if(i == n){
        // print board
        printBoard(board, n);
        return 1; 
    }

    // recusrive case
    // place queen in every row
    int ways = 0;
    for(int j = 0; j <n; j ++){
        // check if current pos is safe
        if(isSafe(board, n, i, j)){
            // place queen
            board[i][j] = 1;
            // place next queen
            ways += solveNQueen(n, board, i + 1);
            // if(success)
            //     return true;
            // remove queen
            board[i][j] = 0;
        }
    }
    return ways;
}
// actual O(N !)  overall O(N^ N)
int main(){
    int n;
    cin >> n;
    int board[20][20] = {0};

    cout << solveNQueen(n, board, 0);
}