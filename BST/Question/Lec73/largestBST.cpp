#include<iostream>
#include<stack>
using namespace std;

// we have to find the largest BST present in a Binary tree.

// Approach 1 : go to every node and check if it is a valid BST counting the number of nodes 
// simultaneously, and return the largest BST. O(n^2) time complexity.

// Approach 2 : we'll save basic info like if that node is valid BST, maxi, mini, size and return
//  it and compare and move.


class info{     // our class that contains maxi,mini,isBST,size of BST jo mila hai ab tak          
public: 
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(TreeNode* root, int &ans){
    if(root == NULL){
      return {INT_MIN, INT_MAX, true, 0};           // agar root NULL hai to max = INT_MIN kiya taaki aage compare ho to smallest value bhi isse badi ho jaaye, similarly for mini we saved INT_MAX.
    }                                               // size = 0 of BST, and of course it is a valid BST. 

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;                      // currNode ke liye class create kari to save the data. 

    currNode.size = left.size + right.size + 1;         // size saved.
    currNode.maxi = max(root->data, right.maxi);        // maxi saved.
    currNode.mini = min(root->data, left.mini);         // mini saved.

    if (left.isBST && right.isBST && (root->data > left.maxi) && (root->data < right.mini)){
        currNode.isBST = true;              // currNode isBST hai ya nhi iski condn check karke update kar di.
    }
    else{
        currNode.isBST = false;
    }

    // maxsize updation.
    if(currNode.isBST){
        ans = max(ans,currNode.size); 
    }
    // return currNode
    return currNode;
}

int largestBST(TreeNode * root){
    int maxsize = 0;            // maxsize ab tak ka max found BST ko save karega
    info temp = solve(root, maxsize);
    return maxsize;
}
