#include<iostream>
#include<queue>
using namespace std;

// lca
// https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
// we have to find lowest common ancestor of two nodes in a tree.

class Solution
{
    public:
    // dry run karoge to aasani se samajh aa jaayga.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //base case
        if(root == NULL)
        {
            return NULL;
        }
        
        if(root->data == n1 || root->data == n2)            // base case ki agar n1 ya n2 me se koi ho to usko return kar do.
        {
            return root;
        }
        
        Node* leftAns = lca(root->left, n1, n2);
        Node* rightAns = lca(root->right, n1, n2);
        
        if(leftAns != NULL && rightAns != NULL)             // dono jagah se non null ka matlab hai jis node per hum khade hai vo hi pehla common ancestor hai because this is a common node to both of them.
        {
            return root;
        }
        else if(leftAns != NULL && rightAns == NULL)        // left non null hai yani n1 ya n2 me se kuchh mil chuka hai, so return it (usko uper jaane do).
            return leftAns;
        else if(leftAns == NULL && rightAns != NULL)        // right me kuch mil chuka hai to usko uper jaane do.
            return rightAns;
        else
            return NULL; 
    }
};