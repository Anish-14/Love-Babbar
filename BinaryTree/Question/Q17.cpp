#include<iostream>
#include<queue>
using namespace std;

// max sum of non adjacent ancestor.
// https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
// max sum btao of non adjacent nodes i.e. koi bhi node jiska sum kar rhe hai vo aaju baaju nhi hone chaiye.
// if a node is contributing in max sum then it's parents and children can not contribute in max sum.


class solution{
    public:

    pair<int,int> solve(Node* root) {
        //base case
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        pair<int,int> res;
        
        // including the present node.
        res.first = root->data + left.second + right.second;
        
        // excluding the present node. 
        res.second = max(left.first, left.second) + max(right.first, right.second);
        
        return res;
        
    }

    int getMax(Node* root){
        pair<int,int> ans = solve(Node* root);
        return max(ans.first,ans.second);
    }
};