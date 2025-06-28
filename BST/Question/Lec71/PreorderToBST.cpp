#include<iostream>
#include<stack>
using namespace std;

// BST from Preorder traversal.

// APPROACH 1
// given a preorder we'll make a node each element and then we'll put next node at it's right place, 
// but it'll take O(n^2) space complexity as we'll take every element and traverse the tree all over 
// again every time. 

// APPROACH 2
// sort preorder now we have inorder, make tree from it with space complexity O(n.logn)

// APPROACH 3
// we want our program in O(n) space cmplexity.
// preorder = N L R   yaani first node is root.
// we'll take help of range concept and by that restriction we'll fill our element in the BST.

BinaryTreeNode<int>* solve(vector<int> &preorder, int mini, int maxi, int &i){
    if(i >= preorder.size()){       // i should not acceed the vector size.
        return NULL;
    }

    if(preorder[i] < mini || preorder[i] > maxi){       // if not lies in the range then return NULL.
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);         // make a root if lies
    root->left = solve(preorder, mini, root->data, i);                         // left part
    root->right = solve(preorder, root->data, maxi, i);                    // right part with appropriate/updated mini and maxi.
    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder)  {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;                  // i iterates the preorder vector.

    BinaryTreeNode<int>* newroot = solve(preorder, mini, maxi, i);
    return newroot;
}

