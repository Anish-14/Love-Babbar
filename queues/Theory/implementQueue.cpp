#include<iostream>
#include<queue>
using namespace std;

// implementation of queue using array.(particularly for int queue)
// It's the simplest version of implementation of queue.
// It's not space optimised solution as when we pop a cell of array,that celll get wasted as if we 
// reached at the end after pushing elements into it, we can not add more elements 
// line no. 40 have some optimisation but still it's not best queue, the circular queues are best.

class Queue{

    int length = 10;
    int *arr = new int[length];
    int front = 0;
    int rear = 0;

    public:

    Queue(int n){
        length = n;
    }

    void push(int n){
        if(rear == length){
            cout<<"queue overflow"<<endl;
            return;
        }
        arr[rear] = n;
        rear++;
    }

    void pop(){
        if(rear == front){
            cout<<"queue underflow"<<endl;
            return;
        }
        arr[front] = -1;    // actually you don't need this statement but I did so that empty cell can be observed.
        front++;
        if(front == rear)   // this is an optimisation, by doing this if the queue gets empty halfway then it restarts itself from (0,0).
        {
            front = 0;
            rear = 0;
        }
    }

    // this fun should return the current size of queue.
    int size(){
       return (rear - front); 
    }

    // tells us if the queue is empty or not.
    bool isEmpty(){
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    // returns the element to be popped(i.e. the front element)
    int frontElement(){
        if(front == rear){
            return -1;
        }
        return arr[front];
    }

    // returns the latest pushed element.
    int backElement(){
        if(front == rear){
            return -1;
        }
        return arr[rear - 1];
    }   
};



int main(){

    Queue q(6);

    q.push(2);
    q.push(23);
    q.push(45);
    q.push(0);
    q.push(8);
    q.push(123);
    q.push(4);      // we added more elements than it's size so it doesn't get inserted to the queue, and a warning that queue overflow comes up.
   
    cout<<q.backElement()<<endl;

    q.pop();
    q.pop();
    
    cout<<q.backElement()<<endl;
    cout<<q.frontElement()<<endl;

    cout<<q.size()<<endl;

    cout<<q.isEmpty()<<endl;
}