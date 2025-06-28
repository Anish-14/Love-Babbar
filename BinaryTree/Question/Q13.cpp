#include<iostream>
#include<queue>
using namespace std;

// Sum of nodes on the longest path from root to leaf node
// https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

class Solution{
public:
    void solve(Node* root, int sum, int &maxSum, int len, int &maxLen) {
        //base case
        if( root == NULL ){
            
            if(len > maxLen)                // agar hume koi naya path mil gya jo ki pichhle longest path se lamba hai, then update it and make it the longest path.
            {
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen) 
            {
                maxSum = max(sum, maxSum);          // agar barabar length ke path hai then jiska sum jyada ho vo aap maxsum me save kar do.
            }
            return;                                 // aur agar len maxlen se chhoti hai yaani koi chhota path mila hai so ignore it.
        }
        
        sum = sum + root->data;
        
        solve(root->left, sum, maxSum, len+1, maxLen);
        solve(root->right, sum, maxSum, len+1, maxLen);

    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0;                // instantaneous length store karega.(filhal length kya chal rhi hai jaha per hum phuche hai)
        int maxLen = 0;             // ye ab tak pahoche huye raasto me se max length ko save kar lega and len>maxlen hone per usko maxlen se update bhi kar dega.
        
        int sum = 0;                // same as above. Stores instantaneous sum.
        int maxSum = INT_MIN;       // stores maxsum of maxlen path founded till now.
        
        solve(root, sum, maxSum, len, maxLen);
        
        return maxSum;
    }
};



// here's another solution
class Solution {
  public:
    pair<int, int> solve(Node* root){
        if(root == NULL){
            return make_pair(0,0);
        }
        
        pair<int, int> leftAns = solve(root->left);
        pair<int, int> rightAns = solve(root->right);
        
        pair<int,int> ans;
        if(leftAns.first > rightAns.first){
            ans.second = leftAns.second + root->data;
            ans.first = leftAns.first + 1;
        }
        else if(leftAns.first == rightAns.first){
            ans.second = max(leftAns.second, rightAns.second) + root->data;
            ans.first = leftAns.first + 1;
        }
        else{
            ans.second = rightAns.second + root->data;
            ans.first = rightAns.first + 1;
        }   
        return ans;
    }
    
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        pair<int, int> ans = solve(root);
        return ans.second;
    }
};

