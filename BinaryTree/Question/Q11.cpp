#include<iostream>
#include<queue>
using namespace std;

// Right & Left side view of a binary tree.


// LEFT SIDE
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void solve(Node* root, vector<int> &ans, int level) {
        //base case
        if(root == NULL)
            return ;
        
        //we entered into a new level    
        if(level == ans.size())                 // har level per 1 hi entry note down karni hai.
            ans.push_back(root->data);

        solve(root->left, ans, level+1); 
        solve(root->right, ans, level+1);        
    }
    
    vector<int> leftView(Node *root)
    {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};



// RIGHT SIDE

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void solve(Node* root, vector<int> &ans, int level) {
        //base case
        if(root == NULL)
            return ;
        
        //we entered into a new level    
        if(level == ans.size())                 // har level per 1 hi entry note down karni hai.
            ans.push_back(root->data);
        
        // left ki jagah right jaao
        solve(root->right, ans, level+1);    
        solve(root->left, ans, level+1);
        
        // is question me ye kabhi sochna ki kya mai line no. 48 waali condn na lagake har baar data
        // ko us particular level ke liye push karu to vo eventually last waala hi push karega ans me 
        // and I'll get my right side view.
    }
    
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};