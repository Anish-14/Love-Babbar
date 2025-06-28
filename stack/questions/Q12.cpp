#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// celebrity problem
// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution {
  public:
    int celebrity(vector<vector<int> >& person) {
        // code here
        int n = person.size();
        bool emptyRow = 0;
        bool fullColumn = 1;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(person[i][j] == 1 && i != j){
                    emptyRow = 0;
                    break;
                }
                emptyRow = 1;
            }
            if(emptyRow){
                // check column
                for(int m = 0; m<n; m++){
                    if(person[m][i] == 0 && m != i){
                        fullColumn = 0;
                    }
                }
                if(fullColumn){
                    return i;
                }
            }
        }
        return -1;
    }
};
