#include<iostream>
#include<queue>
using namespace std;

// flatten a binary tree
// https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
// you have to convert the binary tree into linked list


void flatten(Node* root){
    Node* curr = root;

    while(curr != NULL){
        // agar left me node hai to waha jaao
        if(curr->left){
            Node* pred = curr->left;        // predecessor bol do usko
            // pred ke right most node per jaao and usko curr->right per daal do because pred->right most 
            // node LL ka las element hoga from the left subtree and usko hum chahte hai ki root ke right
            // side laga de
            while(pred->right){
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        // curr ke left ko hume NULL karna hai, to element keval right me hi bacha hai 
        // (jo ki ab left subtree ko point kar rha hai)
        // isse right subtree bhi cover ho jaayega bcoz humne pred->rightmost ko curr->right se jod diya tha
        curr = curr->right;
    }
}