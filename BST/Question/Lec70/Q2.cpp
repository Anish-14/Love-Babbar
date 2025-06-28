#include<iostream>
#include<queue>
using namespace std;

// Validate BST
// check whether a given tree is a BST or not.


// APROACH 1
// find inorder traversal of given tree , if it is sorted then it is a valid BST otherwise it isn't.
// checking that the inorder traversal is sorted or not can be done in O(1) space complexity if we check the previous and current data at every step.


// APROACH 2
// we'll decide range 
// for root range is [int_min , int_max], uske left ke liye range ho jaayegi [int_min, root->data] because root ke left me koi bhi usse bada nhi hona chahiye.
// similarly right range would be [root->data, int_max]             ye example bus root node ke liye tha as recursive calls proceed the ranges will shift accordingly. 

bool isBST(BinaryTreeNode<int> *root, int min, int max){
    if(root == NULL){
        return true;
    }

    if(root->data <= max && root->data >= min){
        bool left = isBST(root->left, min, root->data);     // left call
        bool right = isBST(root->right, root->data, max);   // right call

        return left && right;                   // dono true hona chahiye
    }
    else{
        return false;
    }
}

bool validateBST(BinaryTreeNode<int> *root) {
    return isBST(root, INT_MIN, INT_MAX);
}

