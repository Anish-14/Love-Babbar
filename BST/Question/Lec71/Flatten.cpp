#include<iostream>
#include<stack>
using namespace std;

// Flatten a BST into a Sorted Linked List.
// make the left pointer to NULL and right pointer to next node of LL.

void inorder(TreeNode<int>* root, vector<int> &in){
    if(root == NULL){
        return;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);

}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> inorderVal;
    inorder(root,inorderVal);           // saves the inorder 

    int n = inorderVal.size();

    TreeNode<int>* newRoot= new TreeNode<int>(inorderVal[0]);
    TreeNode<int>*curr = newRoot;

    for(int i = 1; i<n; i++){
        TreeNode<int>* temp = new TreeNode<int>(inorderVal[i]);         // creating new nodes for the value stored in inorder vector.
        
        curr->left = NULL;              // pointing left ptr to NULL.
        curr->right = temp;             // pointing right ptr to next node.
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;             // last vaale ka right bhi NULL ko point karega.

    return newRoot;
}