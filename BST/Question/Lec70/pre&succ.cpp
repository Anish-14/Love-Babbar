#include<iostream>
#include<stack>
using namespace std;


// find predecesor and successor of key.
// predecesor is just smaller value than the given node, successor is just larger value that the given node.
// as given in question key may not be present in the tree, in that case you have to return just smaller value as pre and just larger value as succ.


pair<int, int> predecessorSuccessor(TreeNode *root, int key){
    // find key
    TreeNode * temp =  root;

    int pre = -1;
    int succ = -1;

    while(temp->data != key){
        if(temp->data > key){
            succ = temp->data;             // ye key se badi value thi to ho skta hai ki successor ho. 
            temp = temp -> left;
        }
        else{
            pre = temp->data;               // ye key se chhoti thi to ho skta hai ki predecessor ho.           
            temp = temp->right;
            
        }
        
        if(temp == NULL)                // iska matlab key is not present in the tree.
            break;
    }
   
   pair<int,int> tempAns = make_pair(pre,succ);  
   if(temp == NULL){            // agar key nhi mili us case ka hai ye.
       return tempAns;          // agar key nhi mili iska matlab humne raste me pre and succ find kar liya hai, no need to do the process written below.
   }

    // for key present in the tree.
    TreeNode * leftTree = temp->left;       // pre found key ke left ka rightmost data hoga, as that is just smaller than the key. 
    while(leftTree != NULL){
        pre = leftTree->data;
        leftTree = leftTree->right;
    }

    TreeNode * rightTree = temp->right;     // succ found key ke right ka leftmost data hoga, as that is just larger than the key.
    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int,int> ans = make_pair(pre,succ);
    return ans;
}


