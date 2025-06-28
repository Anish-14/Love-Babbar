#include<iostream>
#include<queue>
using namespace std;

// Diagonal tree
// https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

// khud se kiya hai bhai😎😎😎😎😎
class Solution {
  public:
    void solve(Node* root, map<int, vector<int> > &m, int level){
        if(root == NULL){
            return;
        }
        
        m[level].push_back(root->data);
        
        solve(root->left, m, level+1);
        solve(root->right, m, level);
        
    }
    
    vector<int> diagonal(Node *root) {
        // code here
        vector<int> ans;
        map<int, vector<int> > m; 
        solve(root, m, 0);

        for(auto mp : m){
            for(auto i : mp.second){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};