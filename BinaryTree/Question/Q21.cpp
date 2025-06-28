#include<iostream>
#include<queue>
using namespace std;

// Morris traversal
// TC : O(N)
// SC : O(1)

// ye koi alag type ka traversal nhi hai bus iski space complexity constant hoti hai, so we can use
// it for inorder, preorder traversals


// Do dry run it to understand
vector<int> inOrder(Node* root) {
    vector<int> result;
    Node* curr = root;

    while (curr != NULL) {
        if (curr->left == NULL) {
            // If no left child, visit this node 
            // and go right
            result.push_back(curr->data);
            curr = curr->right;
        }
        else {
            // Find the inorder predecessor of curr
            Node* prev = curr->left;
            while (prev->right != NULL && prev->right != curr) {
                prev = prev->right;
            }

            // Make curr the right child of its 
            // inorder predecessor
            if (prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            } 
            else {
              
                // Revert the changes made in 
                // the tree structure
                prev->right = NULL;
                result.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return result;
}


