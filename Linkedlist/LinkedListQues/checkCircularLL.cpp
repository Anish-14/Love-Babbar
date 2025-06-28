#include<iostream>
using namespace std;

class Node{

    public:

    int data;
    Node* next;

    Node(){
        // default constructor.
    }

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

void print(Node* &head){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp = head;
    while(temp  !=  NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }

    cout<<endl;
    return;
}

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);

    temp -> next = head;
    head = temp;

    return;
}

void insertAtTail(Node* &tail, int d){
    if(tail == NULL){
        cout<<"Empty LL"<<endl;
        return;
    }

    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void insertAtMiddle(Node* &head,Node* &tail,int position,int d){
    // first position
    if(position == 1){
        insertAtHead(head,d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    // last posn
    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }

    Node* nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head,int position){
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* temp = head;
        int cnt = 1;

        while(cnt < position-1){
            temp = temp->next;
            cnt++;
        }

        Node* deletingNode = temp->next;

        temp -> next = deletingNode -> next;
        deletingNode -> next = NULL;
        delete deletingNode;
    }
}

bool circular(Node* head){

    if(head == NULL){
        return true;
    }

    if(head->next == NULL){
        return false;
    }
    else if(head->next == head){
        return true;
    }


    Node* curr = head->next;            

    bool circularLL = false;

    while(curr != NULL  &&  curr != head){
        if(curr->next == NULL){
            circularLL = false;
            break;
        }
        else if(curr->next == head){
            circularLL = true;
            break;
        }

        curr = curr->next;
    }

    return circularLL;
}


int main(){
    Node* node1 = new Node(5);
    // cout<<node1 -> data<<endl;
    // cout<<node1 -> next<<endl; 

    Node* head = node1;
    Node* tail = node1; 

    print(head);
    insertAtHead(head,8);
    print(head);
    insertAtHead(head,9);
    print(head);
    insertAtHead(head,10);
    print(head); 
    insertAtTail(tail,4);
    print(head);
    insertAtMiddle(head,tail,4,7);
    print(head);
    insertAtMiddle(head,tail,5,6);
    print(head);

    // head->next->next->next->next->next->next->next = head;           //this makes it circular LL.

    cout<<circular(head)<<endl;
    // deleteNode(head,1);
    // print(head);
    // deleteNode(head,2);
    // print(head);
    // deleteNode(head,3);
    // print(head);
    // deleteNode(head,4);
    // print(head);
}
