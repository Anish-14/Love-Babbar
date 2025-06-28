#include<iostream>
#include<queue>
using namespace std;

//Function to store the zig zag order traversal of tree in a list.

class Solution{
    public:
	vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> result;
    	if(root == NULL)
    	    return result;
    	
    	queue<Node*> q;
    	q.push(root);
    	
    	bool leftToRight = true;            // to check if we have to print right to left or left to right. 
    	
    	while(!q.empty()) {
    	    
    	    int size = q.size();
    	    vector<int> ans(size);
    	    
    	    //Level Process
    	    for(int i=0; i<size; i++) {
    	        
    	        Node* frontNode = q.front();            // 1 level ki saari nodes ko ek ek karke chunenge
    	        q.pop();
    	        
    	        //normal insert or reverse insert 
    	        int index = leftToRight ? i : size - i - 1;             // forward ya reverse indexing ke hisaab se indexing krenge
    	        ans[index] = frontNode -> data;
    	        
    	        if(frontNode->left)
    	            q.push(frontNode -> left);                  // node ke aage kuch hai to usko q me push kar denge.
    	            
    	        if(frontNode->right)
    	            q.push(frontNode -> right);
    	    }
    	    
    	    //direction change karni h
    	    leftToRight = !leftToRight;                 // after every level we'll change the direction of direction of inserting in the vector.
    	   
    		for(auto i: ans) {
    	    	result.push_back(i);                  // copy in our result.
    	    }  
    	}
    	return result;
    }
};




// Upar wala same logic hai but jab maine khud likhne ki koshish ki to aise likha 
// You should improve your ability to write your algos into code effectively.




// class Solution{
//     public:
//     //Function to store the zig zag order traversal of tree in a list.
//     vector <int> zigZagTraversal(Node* root)
//     {
//         vector<int> result;
//         queue<Node*> q;
//         q.push(root);
        
//     	if(root == NULL){
//     	    return result;
//     	}
    	
//     	bool leftToRight = true;
    	
//     	while(!q.empty()){
//     	    int size = q.size();
//     	    vector<int> ans(size);
    	    
//     	    if(leftToRight){
//     	        for(int i = 0; i<size; i++){
//     	            Node* frontNode = q.front();
    	            
//     	            if(frontNode->left){
//     	                q.push(frontNode->left);
//     	            }
//     	            if(frontNode->right){
//     	                q.push(frontNode->right);
//     	            }
    	            
//     	            ans[i] = frontNode->data;
//     	            q.pop();
//     	        }
//     	    }
    	    
//     	    else{
//     	        for(int i = size-1; i>=0; i--){
//     	            Node* frontNode = q.front();
    	            
//     	            if(frontNode->left){
//     	                q.push(frontNode->left);
//     	            }
//     	            if(frontNode->right){
//     	                q.push(frontNode->right);
//     	            }
    	            
//     	            ans[i] = frontNode->data;
//     	            q.pop();
//     	        }
//     	    }
    	    
//     	    leftToRight = !leftToRight;
    	    
//     	    for(int i = 0; i<size; i++){
//     	        result.push_back(ans[i]);
//     	    }

//     	}
    	
//     	return result;
//     }
// };
