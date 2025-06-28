#include<iostream>
#include<queue>
using namespace std;

// How to implement Binary search trees.

// What's a BST?
// this is kind of sorted tree, where on left hand side of EVERY node 
// all values are smaller then it and on right hand side larger.

// inorder printing of BST is always in increaseing order.  IMP

// Let's implement it.

class Node{

    public:

    int data;
    Node* left ;
    Node* right ;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(Node* root){           // LNR printing (L hamesha R ke left me rahega).Inorder me N beech me rehta hai.
    // base case                    // N matlab print kar do. L matlab left me chale jao.
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){          // NLR  (pre hai isliye N sabse pehle aaya).
    // base case
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left); 
    preorder(root->right);
}

void postorder(Node* root){         // LRN  (post hai isliye N last me aaya).
    // base case
    if(root == NULL){
        return;
    }
    postorder(root->left); 
    postorder(root->right);
    cout<<root->data<<" ";
}

// level order traversal
void levelOrderTraversal(Node* root){
    queue<Node*>q;           // queue banaya to store the nodes.
    q.push(root);           
    q.push(NULL);            // har 1 level ke baad hum NULL daalenge so that we know ki level khatm ho gya hai and it's time to print 'endl'.

    while(!q.empty()){
        
        Node* temp = q.front();
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

Node* minValue(Node* &root){
    // left most jagah pr milegi in a BST. 
    Node* temp = root;
    
    while(temp->left != NULL){
        temp = temp->left;
    }

    return temp;
}

Node* maxValue(Node* &root){
    // right most jagah per jana hai.
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }

    return temp;
}

Node* deleteFromBst(Node* root, int val){
    // base case
    if(root == NULL){
        return NULL;
    }

    if(root->data == val){          // agar mil gya jisko delete karna hai then do the following.
        // 0 child
        if(root->right == NULL && root->left == NULL){
            delete root;
            return NULL;
        }

        // 1 child
        // for right one
        if(root->right != NULL && root->left == NULL){     
            Node* temp = root->right;       // next node save kar li taaki lost na ho.
            delete root;                    // present node ko delete kar do because it's the one.
            return temp;                    // saved node ko uper bhej do.
        }
        // for left one
        if(root->left != NULL && root->right == NULL){     
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // 2 child case
        if(root->left != NULL && root->right != NULL){
            // we can use max value from left also. That'll work as well so we have two different types of solution for this and both are right.
            int min = minValue(root->right)->data;      // right me se min value dhundhi taaki usse replace kar ske.
            root->data = min;                           // value ko present node me copy kiya which has to be deleted.
            root->right = deleteFromBst(root->right, min);      // jisko copy kiya usko delete kar diya.
            return root;                                        // present root ko return kar diya because sab modify ho chuka hai.
        }
    }

    if(root->data < val){
        root->right = deleteFromBst(root->right, val);
        return root;
    }
    else{
        root->left = deleteFromBst(root->left, val);
        return root;
    }
}


Node*  InsertInBst(Node* &root, int data){
    if(root == NULL){
        root = new Node(data);
        return  root;
    }

    if(data <= root->data){
        root->left = InsertInBst(root->left, data);
    } 

    else{
        root->right = InsertInBst(root->right, data);
    }   

    return root; 
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = InsertInBst(root,data); 
        cin>>data;
    }
}

int main(){
    Node* root = NULL;

    cout<<"Enter the data to put in BST "<<endl;
    // 6 8 10 12 9 1 5 -1
    takeInput(root);

    //level order traversal
    cout<<"printing level order traversal "<<endl;
    levelOrderTraversal(root);

    cout << "inorder traversal is:  ";
    inorder(root); 

    cout << endl << "preorder traversal is:  ";
    preorder(root); 

    cout << endl << "postorder traversal is:  ";
    postorder(root);

    root = deleteFromBst(root,10);

    cout<<"printing level order traversal "<<endl;
    levelOrderTraversal(root); 
}