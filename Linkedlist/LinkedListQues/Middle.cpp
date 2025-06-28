#include<iostream>
#include<map>
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
    ~Node() {
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







// FUNCTION FOR FINDIND MIDDLE NODE.


// First 
int getlength(Node* head){
    Node* temp = head;
    int cnt = 0;

    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }

    return cnt;
}
Node* MiddleNode1(Node* head){
    int count = getlength(head);
    int iteration = count/2;        // count kar liya ki kitni baar loop chalana hai.

    Node* Middle = head;
    int i = 0;
    while(i<iteration){
        Middle = Middle->next;
        i++;
    }

    return Middle;
}

// Second
Node* MiddleNode2(Node* head){
    Node* one = head;           // ye ek kadam chalega
    Node* two = head->next;     // ye do kadam chalega 

    // jab tak "two" null per pahochega tab tak "one" middle me pahoch jaayega.

    while(two != NULL){
        two = two->next;
        if(two != NULL){
            two = two->next; 
        }
        one = one->next;
    }

    return one;
}



int main(){ 

    Node* node1 = new Node(6);

    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail,8);
    insertAtTail(tail,10);
    insertAtTail(tail,12);
    insertAtTail(tail,50);

    print(head);

    // Node* Middle = MiddleNode1(head);         // Function 1
    // cout<<Middle->data<<endl;

    Node* Middle = MiddleNode2(head);           // Function 2
    cout<<Middle->data<<endl;


    return 0;
}