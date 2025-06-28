#include<iostream>
#include<queue>
using namespace std;

// minimum to burn the tree.
// https://www.geeksforgeeks.org/problems/burning-tree/1


int findTime(map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mpp, BinaryTreeNode<int>* target){
    queue<BinaryTreeNode<int>*> q; 
    q.push(target); 
    map<BinaryTreeNode<int>*,int> vis;          // a map to keep trach of visited nodes
    vis[target] = 1;
    int time = 0; 

    while(!q.empty()) {
        // queue ke size ki need hai because hum ek baar me queue me kisi node ke child and parent
        //  sab daal rhe hai so we want ki sabko mila ke keval 1 baar time increase ho
        int size = q.size();        
        bool flag = 0;              // flag bnaya to notice ki time badhana hai kya

        for(int i = 0; i<size; i++) {
            auto node = q.front();
            q.pop();
            // koi aisi node neighbour me hai jisko jala skte hai to flag ko 1 kar diya
            // for left
            if(node->left && !vis[node->left]) {
                flag = 1; 
                vis[node->left] = 1; 
                q.push(node->left); 
            }
            // for right
            if(node->right && !vis[node->right]) {
                flag = 1; 
                vis[node->right] = 1; 
                q.push(node->right); 
            }
            // for parent
            if(mpp[node] && !vis[mpp[node]]) {
                flag = 1; 
                vis[mpp[node]] = 1; 
                q.push(mpp[node]); 
            } 
        }
        if(flag)
            time++; 
    }
    return time; 
}

BinaryTreeNode<int>* bfsToMapParents(BinaryTreeNode<int>* root, 
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mpp, int start) {
    queue<BinaryTreeNode<int>*> q; 
    q.push(root); 
    BinaryTreeNode<int>* res; 

    while(!q.empty()) {
        BinaryTreeNode<int>* node = q.front(); 
        // target node ko save kar liya humne, ek teer se do nishaane
        if(node->data == start)
            res = node;     
        q.pop(); 
        // left waale bache ke parent me node daal do 
        if(node->left) {
            mpp[node->left] = node; 
            q.push(node->left); 
        }
        if(node->right) {
            mpp[node->right] = node;
            q.push(node->right); 
        }
    }
    return res; 
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // ek map banaya jisme child to Parent ko connect kar ske because when burning a Node we have to burn
    // all its node including its parent and we don't have child to parent conection in Binary Tree
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> mpp;    

    // by this fun we are also finding the target node
    BinaryTreeNode<int>* target = bfsToMapParents(root, mpp, start); 

    // finally burning the tree
    int maxi = findTime(mpp, target); 
    return maxi; 
}










