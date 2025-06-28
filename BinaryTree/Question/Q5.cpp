#include<iostream>
#include<queue>
using namespace std;

// Sum Tree
// Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.
// An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.


class Solution
{
    public:
    pair<bool,int> isSumTreeFast(Node* root) {
        
        //base case
        if(root == NULL) {
            pair<bool,int> p = make_pair(true, 0);                  // 1st store ki sumTree hai ki nhi, 2nd stores the sum till now on the left or right side of the root node , jisse hum compare karne waale hai.
            return p;
        }
        
        if(root->left == NULL && root->right == NULL ) {                // leaf node condn.
            pair<bool,int> p = make_pair(true, root->data);             // sum me root ka data daal do becoz of leaf node.
            return p;
        }
        
        pair<bool,int> leftAns = isSumTreeFast(root->left);
        pair<bool,int> rightAns = isSumTreeFast(root->right);
        
        bool isLeftSumTree = leftAns.first;                 // left waali subtree SumTree hai ki nhi 
        bool isRightSumTree = rightAns.first;               // right waali subtree SumTree hai ki nhi  
        
        int leftSum = leftAns.second;
        int rightSum = rightAns.second;
        
        bool condn = root->data == leftSum + rightSum;          // condition of SumTree
        
        pair<bool, int> ans;
        
        if(isLeftSumTree && isRightSumTree && condn) {           // verification for this particular subtree/tree.
            ans.first = true;
            ans.second = root->data + leftSum + rightSum ; 
        }
        else{
            ans.first = false;
        }

        return ans;
    }

    bool isSumTree(Node* root){
        return isSumTreeFast(root).first;
    }
};