#include<iostream>
using namespace std;

// N queens puzzle
// chess board(n*n) per n queens rakhni hai such that koi queen ek dusre ko naa maare. 
// https://www.naukri.com/code360/problems/the-n-queens-puzzle_981286?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


void addSolution(vector<vector<int> > &ans, vector<vector<int> > &board, int n){

    // we're just copying our solution into ans, we did this seperately cause more than one solution are possible.
	vector<int> temp;

	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int> > &board, int n){
	int x = row;
	int y = col;

    // while checking safety we just have to check the left part of chess board as we are inserting queen 
    // from left to right therefore nothing is there in the right to check.

	// for left straight chaal
	while(y>=0){
		if(board[x][y] == 1){
			return false;
		}
		y--;
	}

	x = row;
	y = col;
	// checking for Upper left diagonal 
	while(x>=0 && y>=0){
		if(board[x][y] == 1){
			return false;
		}
		y--;
		x--;
	}

	// lower left diagonal
	x = row;
	y = col;
	while(x<n && y>=0){
		if(board[x][y] == 1){
			return false;
		}
		y--;
		x++;
	}

    // agar uper me se kahi koi dikkat nhi hai that means queen is safe.
	return true;
}


void solve(int col, vector<vector<int> > &ans, vector<vector<int> > &board, int n){
    // agar col khatm ho jaaye saare and saari queens place hoti hui aa rhi hai that means you've got one of the answers.
    // base case
	if(col == n){
		addSolution(ans, board, n);
		return ;
	}

	// solve 1 case rest recursion will handle.
    // saari rows me jaake queens rakh rhe hai for a particular column.
	for(int row = 0; row < n; row++){
        // if safe then hum waha queen place kar denge and then next call.
		if(isSafe(row, col, board, n)){
			board[row][col] = 1;

			solve(col+1, ans, board, n);
			// backtracking
			board[row][col] = 0; 
		}
	}
}

vector<vector<int> > nQueens(int n){
    // chess board per jaha jaha queen hai waha 1 hai else 0 hai.

	vector<vector<int> > board(n, vector<int>(n,0));        // shows the chess board
	vector<vector<int> > ans;                       // stores our desirable chess board configuration/ans.

	solve(0, ans, board, n);

	return ans;
}

int main(){
	int n = 8; 
	vector<vector<int> > possibility;
	possibility = nQueens(n);

	cout<<possibility.size()<<endl;
	cout<<possibility[0].size()<<endl;

	int count = 0;
	for(int i = 0; i<possibility.size(); i++){
		for(int j = 0; j<possibility[i].size(); j++){
			count++;
			cout<<possibility[i][j]<<" ";
			if(count%n == 0){
				cout<<endl;
			}
		}
		cout<<endl;
	}

	cout<<possibility.size()<<endl;
	cout<<possibility[0].size()<<endl;
}

