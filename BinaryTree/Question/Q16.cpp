 #include<iostream>
#include<queue>
using namespace std;

// kth ancestor in tree.
// https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
// you have to return the kth ancestor of given node, if not present return -1.


Node* solve(Node* root, int &k, int node) {
    //base case
    if(root == NULL)
        return NULL;
        
    if(root->data == node)              // we are finding our node here, so return the node if found.
    {
        return root;
    }
    
    Node* leftAns = solve(root->left, k, node);                 // go find in left.
    Node* rightAns = solve(root->right, k, node);               // go find in right.


    //wapas
    if(leftAns != NULL && rightAns == NULL)                 // agar left me mil gya then
    {
        k--;                    // as we go up a level k-- so that when k<=0 we'd know that we've reached to the ancestor's node.
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;                    // "K" ko itna bada kar do ki wapas aur uper jaate huye k<=0 na ho ske and humare answer me koi change na ho ske.
            return root;                    // root humara ancestor hai
        }
        return leftAns;                 // agar k waali condn reach nhi hui then return the normal node which we founded.
    }
    
    if(leftAns == NULL && rightAns != NULL) {           // same as above for right case.
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;                // humne same node ko return karwaya hai taaki if K<=0 naa ho paaye, yaani kth ancestor exist na karta ho to 
        //                              // humari vo node return ho rhi hai jo humne find ki thi to hum check karenge ki kya vo node return to nhi ho rhi.
        //                              // agar ho rhi hai then return -1, because vo node khudki ancestor nhi ho skti.
    }

    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);           // we'll get the kth ancestor's node by this fun.
    if(ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}

