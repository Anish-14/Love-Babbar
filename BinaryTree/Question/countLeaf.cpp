#include<iostream>
#include<queue>
using namespace std;

// in this question we have to count the number of leaf nodes in a given tree.
// A leaf node is the node whose left and right pointers points to NULL.

void inorder(BinaryTreeNode<int> * root, int &count) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left, count);             // left side jaao. 
   	
    //leaf node
    if(root->left == NULL && root->right == NULL) {       // jab left side me koi null milega to ye condition check hogi.
        count++;                                          // agar dono side NULL hai to vo leaf node hai.
        return;                                           // no need to check the right part now as it's a leaf node so the right part must be empty.                       
    }
    
    inorder(root->right, count);                          // fir hum right badh jaayenge leaf node dhundhane.    

}


int noOfLeafNodes(BinaryTreeNode<int> *root){
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}