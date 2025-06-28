#include<iostream>
#include<queue>
using namespace std;

// k sum path
// https://www.geeksforgeeks.org/problems/k-sum-paths/1
// wo paths ke number batane hai jinka sum "k" ke barabar ho, a node can start from wherever going in downward direction.

class Solution{
  public:
    void solve(Node* root, int k, int &count, vector<int> path) {
        //base case 
        if(root == NULL)
            return ;
        
        path.push_back(root->data);             // data daalo aage badho
        
        //left
        solve(root->left, k, count, path);
        //right
        solve(root->right, k, count, path);
        
        //check for K Sum
        
        int size = path.size();
        int sum = 0;
        for(int i = size-1; i>=0; i--)  {           //path tak ke saare node->data dal chuke hai now hum peechhe se possibility of sum nikaal lenge,jaha kuchh mila then count++.
            sum += path[i];                         // pichhe se kiya taaki jis node per hum hai uska kaam tamam ho ske.
            if(sum == k)
                count++;                             
        }
        
        path.pop_back();                        // pop the element while backtracking.
    }
     
    int sumK(Node *root,int k)
    {
        vector<int> path;               // to save the node->data jis path tak hum pahoch chuke hai at present time.
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};