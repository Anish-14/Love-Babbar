#include<iostream>
#include<stack>
using namespace std;

// A very Good question
// lec 72 love babbar
// we have to merge two given BST into one.
// love babbar didn't submit the Approach 2 of this question, you can try to submit it
// and see if there's any issue.

// Approach 1 
// find inorder1 of BST1 and inorder2 of BST2, merge both arrays and form a BST from this merged inorder array.
// you've got your merged BST. O(m+n) is both complexities.

// code for Approach 1 :-

void inorder(TreeNode *root, vector<int> &in){
    if(root == NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

vector<int> mergedArrays(vector<int> &v1, vector<int> &v2){
    int i = 0;
    int j = 0;
    vector<int> ans;

    while(i < v1.size()  && j < v2.size()){
        if(v1[i] < v2[j]){
            ans.push_back(v1[i++]);
        }
        else{
            ans.push_back(v2[j++]);
        }
    }

    while (i < v1.size() ) {
        ans.push_back(v1[i++]);
    }

    while (j < v2.size()){
        ans.push_back(v2[j++]);
    }

    return ans;
}

TreeNode* makeBST(vector<int> &v, int s, int e){
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;
    TreeNode* root = new TreeNode(v[mid]);
    root->left = makeBST(v,s,mid-1);
    root->right = makeBST(v,mid+1,e);
    return root;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> v1;
    vector<int> v2;
    inorder(root1,v1);      // inorder saved
    inorder(root2,v2);

    vector<int> merged = mergedArrays(v1,v2);       // merged both arrays
    return merged;

    TreeNode* root = makeBST(merged,0,merged.size());       // made a BST with the sorted array.
    return root;

}






// Approach 2
// step 1:  convert BST into sorted LL. we'll convvert into DLL for new exp.
// step 2:  merge two LLs.
// step 3:  make BST from LL.


// step 1:
void convertIntoDLL(Node* root, Node* &head){  
    if(root == NULL){
        return NULL ;
    }

    // doesn't matter ki pehle hum kaha call maar rhe hai right or left
    // left me agar maarte to uske hisaab se thode adjustment karne padte baaki ans waha se bhi aa jaata
    /*
    // The following are the changes that need to be perfomed if you are doing left traversal first
        root->right = head;
        if(head != NULL)
            head->left = root;
        head = root;

        // A con of this is that head points to the largest node i.e. the rightmost one, but we generally want 
        // the leftmost node to process. Therefore we used the right traversal first
    */
    convertIntoDLL(root->right,head);

    root->right = head;
    if(head != NULL){
        head->left = root;
    }

    head = root;

    convertIntoDLL(root->left,head);
}

// step 2:
Node* mergeTwoLL(Node* &head1, Node* &head2){
    Node* head = NULL;
    Node* tail = NULL;

    while( head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }            
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
             if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }  
        }
    }

    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    return head;
}


// step3 :
int countNodes(Node* head){
    int cnt = 0;
    Node* temp = head;

    while(temp != NULL){
        cnt++;
        temp = temp->right;
    }

    return cnt; 
}

// beautiful code : Dry run to know its beauty!
Node* SortedLLtoBST(Node* &head, int n){
    // binay search waale approach se hum ye BST bnayenge
    
    // base case 
    if(n <= 0  ||  head == NULL){
        return NULL;
    }
   
    // center waale ko node maan kar left bnane ko de denge, left bn ke uska node return hoga jise hum 
    // apne root ke left me laga denge
    Node* left = SortedLLtoBST(head, n/2);      // dummy pointer jisme iski value store hui hai because abhi root bna nhi varna hum root->left me direct ye fun call maar dete

    Node* root = head;
    root->left = left;

    head = head->right;      // head = head->next likha tha pehle maine correction kiya hai, do check it if it feels wrong

    // root ke right me array ke right side ke aadhe elements ko thhus do
    root->right = SortedLLtoBST(head,n-n/2-1);
    return root;            // return our beloved root
}


// our main fun which will call other functions and return the answer.
Node* mergeBST(Node* root1, Node* root2){
    Node* head1 = NULL;
    Node* head2 = NULL;
    convertIntoDLL(root1,head1);
    convertIntoDLL(root2,head2);

    head1->left = NULL;
    head2->left = NULL;
     

    // step 2
    Node* head = mergeTwoLL(head1, head2);

    // step 3
    int n = countNodes(head);
    return SortedLLtoBST(head, n); 

}
