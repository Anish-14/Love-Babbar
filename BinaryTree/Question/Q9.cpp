#include<iostream>
#include<queue>
using namespace std;

// Top view 
// top view se kaisa lagega tree dekhne me vo print karna hai

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> result;
        map<int,int> ans;           // stores hd and node's value.
        queue< pair<Node*,int > > q;         // stores node and hd.
        
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            // check whether hd map me hai ya nhi.
            if(ans.find(hd) == ans.end()){              // agar hd ke liye pehle se mapping hai to hum usme kuch nahi daalenge because hume bus first element of particular hd chaiye.
                ans[hd] = frontNode->data;
            }
            if(frontNode->left){
                q.push(make_pair(frontNode->left ,hd-1));       // left call
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, hd+1));       // right call
            }
        }
        
        for(auto i : ans){
            result.push_back(i.second);
        }
        
        return result;
    }
};