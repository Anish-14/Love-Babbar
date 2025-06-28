#include<iostream>
using namespace std;

class Node {            

    //creating nodes for LinkedList (our own datatype).
    public:              
    int data;           // data of LL.
    Node* next;         // pointer pointing to next location in LL.

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() {                                   // ye destructor samajh nhi aaya
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};

void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}

void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {


    //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}





// FUNCTION FOR REVERSING LL.


// FIRST
void reverseLL1(Node* &head){

    //isme 1 naya pointer na bane for head so that it doesn't take any extra space.

    // base cases
    if(head == NULL  || head->next == NULL){
        return;
    }

    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        head = prev;
    }

    return ;
}

Node* reverseLL2(Node* head){
    // difference between both input is that here an extra pointer is being created
    // dono hi existing LL me change karenge.

    if(head == NULL  || head->next == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    // Node* forward = NULL;

    while(curr != NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        head = prev;
    }

    return prev;
}

//SECOND  Recursive way
Node* reverseLL3(Node* head){

    // base case 
    if(head == NULL || head->next == NULL){

        return head;
    }

    Node* temp = head;
    Node* chhotahead = reverseLL3(head->next);
    temp->next->next = temp;
    temp->next = NULL;

    return chhotahead;
}

// third
void reverse(Node* &head,Node* curr,Node* prev){
    // base case
    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr->next;
    reverse(head,forward,curr);          // for next itertion sabko ek ek badha do.
    curr->next = prev;

    return;
}
Node* reverseLL4(Node* head){

    Node* curr = head;
    Node* prev = NULL;
    reverse(head,curr,prev);
    return head;
}

int main(){
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail,12);
    insertAtHead(head,8);
    insertAtHead(head,6);
    insertAtTail(tail,50);

    print(head);

    // head = reverseLL2(head);
    // reverseLL1(head);
    head = reverseLL4(head);

    print(head);

    return 0;
}