#include<iostream>
#include<queue>
using namespace std;

// we are implementing tree
// we have to implement it on our own.


// class of Node of Tree.
class node{

    public:

    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// we are building the tree by taking the data, if data == -1 then we'll put a  NULL pointer there.
// 1
// 3 5                  // this type of tree will be constructed if '1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1' this is given as input.
// 7 11 17
node* buildTree(node* root){
    int data;
    cout<<"Enter the data: "<<endl;     // data lekar uska node bana diya.
    cin>>data;
    root = new node(data);              // root ko us node per point karwa diya.

    if(data == -1){                     
        return NULL;
    }

    cout<<"Enter left side of "<<data<<endl;
    root->left = buildTree(root->left);                     // left ke data ko connect kar rahe hai.
    cout<<"Enter right side of "<<data<<endl;
    root->right = buildTree(root->right);                   // right ke data ko connect kar rahe hai.

    return root;
}

//we want to traverse the tree in a way such that we go from top to bottom and in Left to Right way.
void levelOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    queue<node*>q;           // queue banaya to store the nodes.
    q.push(root);           
    q.push(NULL);            // har 1 level ke baad hum NULL daalenge so that we know ki level khatm ho gya hai and it's time to print 'endl'.

    while(!q.empty()){
        
        node* temp = q.front();
        q.pop();

        if(temp == NULL){               // agar NULL hua to endl print karwa diya.
            cout<<endl;
            if(!q.empty()){             // agar queue khaali nhi hui iska matlab neeche aur bhi levels hai so unko seperate karne
                q.push(NULL);           // ke liye ye NULL lagaya taaki aage ke levels se vo seperate ho sake.
            }
        }
        else{
            cout<<temp->data<<" ";      // printing the data.

            if(temp->left){
                q.push(temp->left);     // left ka data queue me bhar diya.
            }
            if(temp->right){
                q.push(temp->right);    // right ka data queue me bhar diya.
            }
        }

    }
}

void inorder(node* root){            // LNR printing (L hamesha R ke left me rahega).Inorder me N beech me rehta hai.
    // base case                    // N matlab print kar do. L matlab left me chale jao.
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){          // NLR  (pre hai isliye N sabse pehle aaya).
    // base case
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left); 
    preorder(root->right);
}

void postorder(node* root){         // LRN  (post hai isliye N last me aaya).
    // base case
    if(root == NULL){
        return;
    }
    postorder(root->left); 
    postorder(root->right);
    cout<<root->data<<" ";
}


// jaise level order traverse kiya tha vaise hi we want to build the tree in that way of input.
// we gave &root because we want changes to happen simultaneously.
void buildFromLevelOrder(node* &root){
    queue<node*> q;
    
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    if(data == -1){
        return ;
    }
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"enter left side node for "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter right side node for "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

int main(){
    node* root = NULL;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1   to insert the elements in the tree from buildtree(root) function.
    // root = buildTree(root);

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1  for buildfromlevelorder(root) fun ke liye input.
    buildFromLevelOrder(root);

    // cout<<"level order travesal output"<<endl;
    levelOrderTraversal(root);

    cout << "inorder traversal is:  ";
    inorder(root); 

    cout << endl << "preorder traversal is:  ";
    preorder(root); 

    cout << endl << "postorder traversal is:  ";
    postorder(root); 

}