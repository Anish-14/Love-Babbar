#include<iostream>
#include<queue>
using namespace std;

// we have to count the longest node chain.
// 1 3 5 7 11 17         ans should be 3.
// 5 8 6 3 N 7 N N N 8 N 9 10.   ans should be 5
// N            ans should be zero.
// 1            ans should be 1.


class Solution{
    public:
    //Function to find the height of a binary tree.
    void countAllDepth(struct Node* &node, vector<int> &v,int &count){
        // as count starts from 1 so it has counted the root node already.
        // for "N" tree we will return zero in the original fun itself so we don't have to worry about that.


        // base condn
        if(node == NULL){
            v.push_back(count);
            return ;
        }
        
        if(node->left != NULL){         // agar left me node hai to count++ kar do.
            count++;
        }
        
        countAllDepth(node->left,v,count);
        
        if(node->left == NULL && node->right == NULL){          // agar leaf node hai to no need to go to the right side of it.
            count--;                                // as we are going back we need to count-- so that aage sab sahi se ho ske.
            return;
        }
        
        if(node->right != NULL){                // same as left waala.
            count++;
        }
        
        countAllDepth(node->right,v,count);

        count--;                        // we did this count-- because when line number 41 has been executed the function will return to the previous node.
        //                              // as we have returned to the previous node so it's important to count-- as mentioned earlier.
    }
    
    int height(struct Node* node){
        // code here 
        int count = 1;
        vector<int> v;
        int height;
        
        if(node == NULL){
            return 0;
        }
        
        countAllDepth(node,v,count);
        
        int maxi = INT_MIN;                 // vector me se maximum nikaal liya.
        for(int i = 0; i<v.size(); i++){
            if(v[i] > maxi){
                maxi = v[i];
            }
        }
        
        height = maxi;
        
        return height;
    }
};



// LOVE BABBAR'S SOLUTION

int height(struct Node* node){
    // base case
    if(node == NULL){
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left,right) + 1;
    return ans;
}
