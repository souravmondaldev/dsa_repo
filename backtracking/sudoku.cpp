#include<bits/stdc++.h>
using namespace std;

void printBoard(int matr[][9], int n){
    for(int i = 0 ; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cout << matr[i][j] << " ";
        }
        cout <<endl;
    }
}

bool isSafe(int matr[][9], int row, int col, int num){
    for(int i = 0; i < 9; i ++){
        if(matr[row][i] == num)
            return false;
    }
    for(int i = 0; i < 9; i ++){
        if(matr[i][col] == num)
            return false;
    }
    int row_start = (row / 3) * 3;
    int col_start = (col / 3) * 3;
    for(int i = row_start; i < row_start + 3; i ++){
        for(int j = col_start; j < col_start + 3; j ++){
            if(matr[i][j] == num)
                return false;
        }
    }
    return true;
}
// O((9!) ^ 9)
bool solveSudoku(int mat[][9], int i, int j, int n){
    //base case
    if(i == n){
        printBoard(mat, n);
        return true;
    }
    //rec case
    if(j == n){
        return solveSudoku(mat, i + 1, 0, n);
    }
    // skip prefilled cells
    if(mat[i][j] != 0)
        return solveSudoku(mat, i, j + 1, n);

    for(int num = 1; num <= n; num ++){
        if(isSafe(mat, i, j, num)){
            mat[i][j] = num;
            if(solveSudoku(mat, i, j + 1, n))
                return true;
        }
    }
    mat[i][j] = 0;
    return false;
}
int main(){
    int n = 9;
    int mat[9][9] = { 
         {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} };

    if(!solveSudoku(mat, 0 , 0 , n)){
        cout << "No solution" << endl;
    }
}