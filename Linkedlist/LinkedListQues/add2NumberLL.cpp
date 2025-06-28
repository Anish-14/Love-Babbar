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

void insertAtPosition(Node* &head,Node* &tail,int position,int d){
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




int returnSum(Node* head1, Node* head2){
    Node* curr1 = head1;
    int sum1 = 0;
    while(curr1 != NULL){
        sum1 = sum1 * 10 + curr1->data;
        curr1 = curr1 -> next;
    }

    Node* curr2 = head2;
    int sum2 = 0;
    while(curr2 != NULL){
        sum2 = sum2 * 10 + curr2->data;
        curr2 = curr2 -> next;
    }

    int total = sum1 + sum2;

    return total;
}




int main()
{

    Node* node1 = new Node(7);
    Node* head1 = node1;
    insertAtHead(head1,8);

    Node* node2 = new Node(5);
    Node* head2 = node2;

    insertAtHead(head2,5);
    insertAtHead(head2,8);

    print(head1);
    print(head2);

    int totalSum = returnSum(head1,head2);
    cout<<"total of both numbers is -> "<<totalSum<<endl;
    
    return 0;
}


// Love Babbar's solution
class Solution
{
    private:
    Node* reverse(Node* head) {
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void insertAtTail(struct Node* &head, struct Node* &tail, int val) {
        
        Node* temp = new Node(val);
        //empty list
        if(head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail -> next = temp;
            tail = temp;
        }
    }
    
    struct Node* add(struct Node* first, struct Node* second){
        int carry = 0;
        
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0) {
            
            int val1 = 0;
            if(first != NULL)
                val1 = first -> data;
                
            int val2 = 0;
            if(second !=NULL)
                val2 = second -> data;
            
            
            int sum = carry + val1 + val2;
            
            int digit = sum%10;
            
            //create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            if(first != NULL)
                first = first -> next;
            
            if(second != NULL)
                second = second -> next;
        }
        return ansHead;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        //step 1 -  reverse input LL
        first = reverse(first);
        second = reverse(second);
        
        //step2 - add 2 LL
        Node* ans = add(first, second);
        
        //step 3 
        ans = reverse(ans);
        
        return ans;
    }
};

