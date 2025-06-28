#include<iostream>
#include<stack>
using namespace std;

// find lowest common ancestor of two given node.

TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q){
    if(root == NULL){
        return NULL;
    }

    if(root->data < P->data && root->data < Q->data){       // dono bade hai root se iska matlab answer lies in right side. 
        return LCAinaBST(root->right, P, Q);
    }
    if(root->data > P->data && root->data > Q->data){       // answer lies lies in left side.
        return LCAinaBST(root->left, P, Q);
    }

    return root;            // agar 1 left side and 1 right side ho gya iska matlab jis node per hum khade hai that is the LCA.
}


// In iterative way to save space

TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    while(root != NULL){
        if(root->data < P->data && root->data < Q->data){       // dono bade hai root se iska matlab answer lies in right side. 
            root = root->right;
        }

        else if(root->data > P->data && root->data > Q->data){       // answer lies lies in left side.
            root = root->left;
        }

        else{
            return root;
        }
    }

    return NULL;
}


