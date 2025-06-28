#include<iostream>
using namespace std;

// Sudoku solver
// https://www.naukri.com/code360/problems/sudoku-solver_699919?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// TC = 9^n     where n is the number of empty cells in the sudoku
// SC = O(1)    because function call stack me had se had 81 calls jaayengi and uske liye O(81) ka space jaayega which is constant


bool isSafe(int row, int col, vector<vector<int>>& board, int val){
    for(int i = 0; i<board[0].size(); i++){
        // row check
        if(board[row][i] == val){
            return false;
        }
        // col check
        if(board[i][col] == val){
            return false;
        }
        // 3*3 matrix check
        // try it, it works
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val){
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>>& board){
    int n = board[0].size(); 

    // iterating through each cell
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){

            // cell empty
            if(board[row][col] == 0){
                // saari values daalke check karo
                for(int val = 1; val<=9; val++){
                    if(isSafe(row,col,board,val)){
                        board[row][col] = val;
                        // recursive call
                        bool aageSolutionPossible = solve(board);
                        if(aageSolutionPossible){
                            return true;
                        }
                        else{
                            // backtrack
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true; 
}

void solveSudoku(vector<vector<int>>& sudoku){
    // fuction call
	bool fuctioncall = solve(sudoku);
}
