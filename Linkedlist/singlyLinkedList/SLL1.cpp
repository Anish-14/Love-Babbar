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
        // this will delete all nodes next to the node also if there is any
        if(this->next != NULL) {
            // this recursively calls the destructor
            delete next;
            // apne node->next ko NULL kar diya taaki kisi arbitrary location per point na kar rha ho ye 
            // as next node jisko ye point kar rha hai vo delete ho chuki hai
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
        // ye destructor khatm hote hi jiske liye tumne call kiya tha vo finally delte ho jaayega
    }

    // example  10->20->30  is a LL
    // delete(10) will give output as
    // memory is free for node with data 30
    // memory is free for node with data 20
    // memory is free for node with data 10

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
        //memory free start node
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

// below this you haven't learned in lec 44.

bool isCircularList(Node* head) {
    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;
}

bool detectLoop(Node* head) {

    if(head == NULL)
        return false;

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp !=NULL) {

        //cycle is present
        if(visited[temp] == true) {
            cout << "Present on element " << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;

    }
    return false;

}

Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow -> next;
        fast = fast->next->next;
        
        if(slow == fast) {
            cout << "present at " << slow -> data << endl;
            return slow;
        }
    }

    return NULL;

}

Node* getStartingNode(Node* head) {

    if(head == NULL) 
        return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow;

}

void removeLoop(Node* head) {

    if( head == NULL)
        return;

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 

    temp -> next = NULL;

}


int main() {
    
    //created a new node in heap memory that's why we are using pointers.
    Node* node1 = new Node(10);
    cout << node1 -> data << endl;                    // access data.
    cout << node1 -> next << endl;                    // access the address of next node. 
    
    //head pointed to node1
    Node* head = node1; 
    Node* tail = node1;
    // all three have same address, means all three are the pointer pointing to the created node in heap memory
    cout<<tail<<endl;
    cout<<node1<<endl;
    cout<<head<<endl;
    print(head);

    insertAtTail(tail, 12);

    print(head);
    
    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(tail,head, 2, 22);
    print(head);    

    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;

    deleteNode(4, head);
    

    tail -> next = head ->next;

    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;
    //print(head);

    if(floydDetectLoop(head) != NULL) {
        cout << "Cycle is present " << endl;
    }
    else
    {
        cout << "no cycle" << endl;
    }

    Node* loop = getStartingNode(head);

    cout << "loop starts at " << loop -> data  << endl;

    removeLoop(head);
    print(head);

    /*
    print(head);

    if(isCircularList(head)) {
        cout << " Linked List is Circular in nature" << endl;
    }
    else{
        cout << "Linked List is not Circular " << endl;
    }
    */


    return 0;
}
