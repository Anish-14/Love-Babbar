#include<iostream>
#include<queue>
using namespace std;

// Balanced Tree
// Given a binary tree, find if it is height balanced or not.
// FOR ALL nodes check karna hai.  
// A tree is height balanced if difference between heights of left and right subtrees is not more than one FOR ALL nodes of tree

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    pair<bool, int> isBalancedFast(Node* root) {
        // base case
        if(root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);         // 1st represent ki balanced hai ki nahi , 2nd rep the height.
            return p;
        }
        
        pair<int,int> left = isBalancedFast(root->left);
        pair<int,int> right = isBalancedFast(root->right);
        
        
        bool leftAns = left.first;                  // left me balanced hai ya nhi btayega ye.
        bool rightAns = right.first;
        
        bool diff = abs (left.second - right.second ) <= 1;          // given condn
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;            // height update karke ans me daal di.
        
        if(leftAns && rightAns && diff) {                           // condn for a balanced tree/subtree.
           ans.first = true;
        }
        else{
            ans.first = false;
        }
        
        return ans;
    }
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
    
};