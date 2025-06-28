#include<iostream>
using namespace std;

// Rat in a maze 
// return path in alphabetical order
// https://www.naukri.com/code360/problems/rat-in-a-maze_1215030?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// TC is 4^(n^2)        exponential time complexity

bool isSafe(int newx, int newy, vector < vector < int >> & arr,
 vector<vector<bool> > &visited, int n){

    // function to check if moving in a particular direction is possible or not.
    if( (newx >= 0 && newx < n) && (newy >= 0 && newy < n) && arr[newx][newy] == 1 && 
    visited[newx][newy] == 0){
        return true;
    }
    else{
        return false;
    }
}

void solve(int x, int y, vector < vector < int > > & arr, int n, vector<string> &ans,
    vector<vector<bool> > &visited, string path){

        // base case
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return ;
        }

        // 4 movement
        // alphabetically liye taaki lexiographical order me koi dikkat na ho from starting.
        // D L R U
        visited[x][y] = 1;

        // Down
        // Down jaane per row badh jaayegi and col will remain same, so we will check if going there is safe or not and then proceed
        if(isSafe(x+1, y, arr, visited, n)){
            solve(x+1, y, arr, n, ans, visited, path + 'D');
        }

        // Left
        if(isSafe(x, y-1, arr, visited, n)){
            solve(x, y-1, arr, n, ans, visited, path + 'L');
        }

        // Right
        if(isSafe(x, y+1, arr, visited, n)){
            solve(x, y+1, arr, n, ans, visited, path + 'R');
        }

        // Up
        if(isSafe(x-1, y, arr, visited, n)){
            solve(x-1, y, arr, n, ans, visited, path + 'U');
        }
        
        // in backtracking we will remove the tag of visited so that if there is any other path
        // that involves that cell then that path can also be included in the ans.
        visited[x][y] = 0;
    }

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;     // store answer
    vector<vector<bool> > visited(n, vector<bool> (n,0));      // to mark ki humne kaha kaha pair rakh diya hai.
    string path = "";       // throughout path store karta rahega that where are we from starting.

    // edge case
    if(arr[0][0] == 0){        // pehle per hi nhi jaa paayega apna rat
        return ans;
    }

    solve(0,0,arr,n,ans,visited,path);  
    return ans;     
}