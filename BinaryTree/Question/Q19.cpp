#include<iostream>
#include<queue>
using namespace std;

// construct a binary tree from inorder and postorder traversal. 

class Solution{
    public:
    
    // O(nlogn) TC me hoga ye mapping create
    void creatMapping(int in[], map<int, int> &NodeToIndex, int n){
        for(int i = 0; i<n; i++){
            NodeToIndex[in[i]] = i;
        }
    }
    
    Node* makeTree(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &NodeToIndex){
        // base case
        if(index < 0 || inorderStart > inorderEnd){
            return NULL; 
        }
        
        // pre ka first element will be root
        int element = post[ index++];
        Node* root = new Node(element);
        
        // found the position on root in inorder.
        int position = NodeToIndex[element];
        
        
        // post order me right me pehle call maarni padegi
        root->right = makeTree(in, post, index , position + 1, inorderEnd, n, NodeToIndex);
        root->left = makeTree(in, post, index , inorderStart, position - 1, n, NodeToIndex);
        
        return root;
    }
    
    Node* buildTree(int in[],int post[], int n){
        int postorderIndex = n-1;
        map<int, int> NodeToIndex;

        createMapping(in, NodeToIndex, n);
        // function call
        Node* ans = makeTree(in, post, postorderIndex, 0, n-1, n, NodeToIndex);
        
        return ans;
    }
};