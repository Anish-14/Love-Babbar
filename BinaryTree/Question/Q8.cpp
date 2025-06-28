#include<iostream>
#include<queue>
using namespace std;

// this was a tough one for me, do try it next time
// Vertical Order traversal
// https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1


class Solution{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int, map<int,vector<int> > > nodes;     // Hum distance from root node , level , value of node  ek jagah store karenge
        queue< pair<Node*, pair<int,int> > > q;     // is queue me humne Node , distance and level daali hai taaki node travere karte karte hum distance and level store kara ske in our main answer.
        vector<int> ans;                            // we have to return this.
        
        if(root == NULL)
            return ans;
            
        q.push(make_pair(root, make_pair(0,0)));        // pushed our root 
        
        while(!q.empty()) {                             // level order traversal
            pair<Node*, pair<int,int> > temp = q.front();       // taking the first element
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second.first;             // hd stands for "horizontal distance".
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode->data);          // nodes me humne apni info save kar li.
            
            if(frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1) ));            // left ke liye call maar di. left me hd 1 se ghat jaayegi. lvl ko to badhna hi hai.
                
            if(frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));           // same right ke liye kar diya.
        }
        
        for(auto i: nodes) {                    // traversed out nodes to get the value saved in the vector there and copied in ans.
            
            for(auto j : i.second) {  
                         
                for(auto k : j.second)      // j.second also contains a map so we've to iterate through it
                {
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};




