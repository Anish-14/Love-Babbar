#include<iostream>
#include<queue>
using namespace std;

// Construct Tree from Inorder & Preorder
// https://www.geeksforgeeks.org/problems/construct-tree-1/1



class Solution{
    public:
    
    int findPos(int in[], int &element, int &n){
        // finding the index of the element in inorder
        for(int i = 0; i<n; i++){
            if(in[i] == element){
                // for duplicate data bhi work karna chahiye, so we changed the element when we found, so that if there's a duplicate of it then also the index returns of the right one.
                in[i] = INT_MIN;
                return i;
            }
        }
        return -1;    
    }
    
    Node* makeTree(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n){
        // base case
        if(index >= n || inorderStart > inorderEnd){
            return NULL; 
        }
        
        // pre ka first element will be root
        int element = pre[index++];
        Node* root = new Node(element);
        
        // found the position on root in inorder.
        int position = findPos(in, element, n);
        
        root->left = makeTree(in, pre, index , inorderStart, position - 1, n);
        root->right = makeTree(in, pre, index , position + 1, inorderEnd, n);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n){
        int preorderIndex = 0;
        // function call
        Node* ans = makeTree(in, pre, preorderIndex, 0, n-1, n);
        
        return ans;
    }
};

