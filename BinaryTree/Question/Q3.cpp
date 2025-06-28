#include<iostream>
#include<queue>
using namespace std;

// Diameter of tree
// It is the longest possible chain of nodes in a tree.
 

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  private:
    
  public:

    // Function to return the diameter of a Binary Tree.
    pair<int,int> diameterFast(Node* root) {
        //base case
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);               // first block represents diameter and 2nd rep height.
            return p;
        }
        
        pair<int,int> left = diameterFast(root->left);      // left ke liye call
        pair<int,int> right = diameterFast(root->right);    // right ke liye call
        
        int op1 = left.first;           // option 1 (left subtree me hai longest chain)
        int op2 = right.first;          // option 2 (right subtree me hai)
        int op3 = left.second + right.second + 1;       // left and right ke combo me hai longest chain (so left + right + 1 for the root node to return our ans as diameter.)
        // humne yaha height ka use isliye kiya becoz yha left ka diameter height ke equal ho jaayega kyuki isme root involved hai to left waale ko root se judna hi padega
        // jiski wajah se left ka diameter = left ki height ho jaayega therefore we need height.

        pair<int,int> ans;
        ans.first = max(op1, max(op2, op3));                    // firt contain diameter (jo bhi option usko maximise karega vo hi diameter ho jaayega).
        ans.second = max(left.second , right.second) + 1;           // second contains height.

        return ans;
    }

    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};
