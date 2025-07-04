#include<iostream>
#include<stack>
using namespace std;

// convert a BST into a min heap.
// Given BST is also a complete binary tree. The problem is to convert the given BST into a Min Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied to all the nodes, in the resultant converted Min Heap

// example:
// Input:            4
//                 /   \
//               2     6
//             /  \   /  \
//           1     3 5    7  

// Output:          1
//                /   \
//              2     5
//            /  \   /  \
//          3     4 6    7 
// Explanation: The given BST has been transformed into a Min Heap. All the nodes in the Min Heap satisfies the given condition, that is, values in the left subtree of a node should be less than the values in the right subtree of the node. 


 
// Structure of a node of BST
struct Node {
 
    int data;
    Node *left, *right;
};
 
/* Helper function that allocates a new node
   with the given data and NULL left and right
   pointers. */
struct Node* getNode(int data)
{
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
// function prototype for preorder traversal
// of the given tree
void preorderTraversal(Node*);
 
// function for the inorder traversal of the tree
// so as to store the node values in 'arr' in
// sorted order
void inorderTraversal(Node* root, vector<int>& arr)
{
    if (root == NULL)
        return;
 
    // first recur on left subtree
    inorderTraversal(root->left, arr);
 
    // then copy the data of the node
    arr.push_back(root->data);
 
    // now recur for right subtree
    inorderTraversal(root->right, arr);
}
 
// function to convert the given BST to MIN HEAP
// performs preorder traversal of the tree
void BSTToMinHeap(Node* root, vector<int> &arr, int* i)
{
    if (root == NULL)
        return;
 
    // first copy data at index 'i' of 'arr' to
    // the node in NLR way .
    root->data = arr[++*i];
 
    // then recur on left subtree
    BSTToMinHeap(root->left, arr, i);           // &i nhi aayega yaha because ye waala i pointer hai naki int value
 
    // now recur on right subtree
    BSTToMinHeap(root->right, arr, i);
}
 
// utility function to convert the given BST to
// MIN HEAP
void convertToMinHeapUtil(Node* root)
{
    // vector to store the data of all the
    // nodes of the BST
    vector<int> arr;
    int i = -1;
 
    // inorder traversal to populate 'arr'
    inorderTraversal(root, arr);
 
    // BST to MIN HEAP conversion
    BSTToMinHeap(root, arr, &i);
}
 
// function for the preorder traversal of the tree
void preorderTraversal(Node* root)
{
    if (!root)
        return;
 
    // first print the root's data
    cout << root->data << " ";
 
    // then recur on left subtree
    preorderTraversal(root->left);
 
    // now recur on right subtree
    preorderTraversal(root->right);
}
 
// Driver program to test above
int main()
{
    // BST formation
    struct Node* root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);
 
    // Function call
    convertToMinHeapUtil(root);

    // humne is hisaab se BST to minheap me convert kiya hai ki preorder increasing order me aa jaaye
    cout << "Preorder Traversal:" << endl;
    preorderTraversal(root);
 
    return 0;
}