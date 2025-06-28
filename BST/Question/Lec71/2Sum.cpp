#include<iostream>
#include<stack>
using namespace std;


// 2 sum in BST
// given a target you have to find two nodes in BST whose sum is the target.

// APPROACH 1
// I will go at every node and then search for the value which will add up and make the target.(O(n^2) nearly).


// APPROACH 2
// find inorder of BST and then usme check karo sum. O(n) space and O(log(n)) will be time complexity.

void inorder(BinaryTreeNode<int>* root, vector<int> &inorderData){
    if(root == NULL){
        return NULL;
    }

    inorder(root->left,inorderData);
    inorderData.push_back(root->data);
    inorder(root->right,inorderData);

}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
    vector<int> inorderData;
    inorder(root,inorderData);          // saves inorder of the BST.

    int i = 0, j = inorderData.size();

    while(i<j){
        int sum = inorderData[i] + inorderData[j];          // Binary search algorithm to find the sum.
        if(sum == target){
            return true;
        }
        else if(sum > target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}