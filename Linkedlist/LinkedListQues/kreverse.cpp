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



Node* kreverse(Node* head, int k){
    // base case
    if(head == NULL){
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;

    while(curr != NULL && count<k){                           // will reverse the k group.
        next = curr->next;            
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // kreverse will return the head of the reversed LL which recursion had done now we have to join
    // it by head .
    if(next != NULL){
        head->next = kreverse(next,k);  
    }        

    return prev;                // prev is the head after reversing.
}




int main(){
    Node* node1 = new Node(5);

    Node* head = node1;
    Node* tail = node1; 

    cout<<"hi"<<endl;

    insertAtHead(head,8);
    // print(head);
    insertAtHead(head,9);
    // print(head);
    insertAtHead(head,10);
    // print(head); 
    insertAtTail(tail,4);
    // print(head);
    insertAtPosition(tail,head,4,7);
    // print(head);
    // insertAtPosition(tail,head,5,6);
    print(head);

    cout<<"by"<<endl;

    Node* matha = kreverse(head,2);
    print(matha);
    print(head);
}






// this fun is not working, figure out why?
Node* kreverse(Node* head, int k){
    // base case
    if(head == NULL  || head->next == NULL){
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(k){                           // will reverse the k group.
        next = curr->next;            
        curr->next = prev;
        prev = curr;
        curr = next;
        k--;
    }

    // kreverse will return the head of the reversed LL which recursion had done now we have to join
    // it by head .
    
    head->next = kreverse(next,k);  
           

    return prev;                // prev is the head after reversing.
}

