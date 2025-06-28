#include<iostream>
#include<stack>
using namespace std;


// create a balanced BST from given Normal BST.

// APPROACH 
// inorder lo then uske mid element ko root bnao, uske left waale ko left me bhej do and right waale ko right me.
// Do this recursively and you'll have your balanced BST.


void inorder(TreeNode<int>* root, vector<int> &in){
    if(root == NULL){
        return;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

TreeNode<int>* inorderToBST(int s, int e, vector<int> &in){
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;          // mid element

    TreeNode<int>* root = new TreeNode<int>(in[mid]);       // node for mid ele
    root->left = inorderToBST(s,mid-1,in);                  // uske left ke liye call maar di 
    root->right = inorderToBST(mid+1,e,in);                 // right ke liye.

    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inorderval;
    inorder(root,inorderval);       // save inorder values of Normal BST.

    int s = 0, e = inorderval.size()-1;

    TreeNode<int>* newroot = inorderToBST(s,e,inorderval);      // function call for balanced BST.
    return newroot;
}
