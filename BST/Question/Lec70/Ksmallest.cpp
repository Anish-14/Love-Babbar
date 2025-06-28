#include<iostream>
#include<stack>
using namespace std;


// find Kth smallest node.

// APROACH 1
// find it's inorder and return the kth smallest element.


// APROACH 2
// traverse the BST just like inorder and keep track. (you'll save space)

int solve(BinaryTreeNode<int>* root, int k, int &i){
    //base case
    if(root == NULL){           // i store kar rha hai ki hmne kitne smallest nodes ko traverse kar liya hai.
        return -1;              // jaise hi i == k ho jaayega, we'll return.
    }

    //Left me call maar do. (LNR)
    int left = solve(root->left,k,i);
    if(left != -1){             // agar left se NULL nhi aa rha matlab answer aa rha hai so return it taaki root tak pahoch ke finally return ho ske.
        return left;
    }

    //N
    i++;                        // we're on the root, so i++ kar ke count kar liya
    if(i == K){                 // check ki pahoch gye kya apne nirdharit sthaan per.
        return root->data;      // if yes then return.
    }

    // R
    return solve(root->right,k,i);

}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i = 0;
    return solve(root,k,i);
}


// agar Kth largest puchhe to "n-k+1" smallest element bata dena.