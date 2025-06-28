#include<iostream>
#include<queue>
using namespace std;

// search a node in BST.
// https://www.naukri.com/code360/problems/search-in-bst_1402878   CODING NINJAS.

// Node ka naam BinaryTreeNode<T> tha question me . Template was used to generalise the Node in the question.

BinaryTreeNode<int>* findNode(BinaryTreeNode<int>* &root, int k){
    if(root == NULL){
        return NULL;
    }
    if(root->data == k){
        return root;
    }

    if(root->data < k){
        BinaryTreeNode<int>* rightans = findNode(root->right, k);
        return rightans;
    }
    else{
        BinaryTreeNode<int>* leftans = findNode(root->left, k);
        return leftans;
    }

}

bool searchInBST(BinaryTreeNode<int>* root, int x) {
    BinaryTreeNode<int>* ans = findNode(root, x);

    if(ans == NULL){
        return 0;
    }
    else{
        return 1;
    }
}


// LOVE BABBAR'S SOLUTION
// He used the iterative solution to reduce the space complexity of the solution

bool searchInbst(Node* root , int x){
    Node* temp = root;

    // jab tak NULL na ho tab tak chalao because if dhundhte dhundhte NULL ho gya temp that means ki required Node present hi nhi hai as it is a BST.
    while(temp != NULL){                    
        if(temp->data == x){
            return true;
        }

        // agar nhi mila to 
        if(temp->data <= x){            
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }

    return false;
}



