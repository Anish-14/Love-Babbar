#include<iostream>
#include<queue>
using namespace std;

// we have to implement circular queues in array.
// in circular queues if the last box of array is filled but you've popped some data so the starting
// boxes are empty so you wanna use those boxes to make the queue space optimised.


class Queue{

    int length = 10;
    int *arr = new int[length];
    int front = -1;
    int rear = -1;

    public:

    Queue(int n){
        length = n;
    }

    void push(int n){
        if((rear == length-1 && front == 0) || (rear == front - 1)){    // full queue condition.
            cout<<"the queue is full"<<endl;
            return;
        }

        else if(front == -1 && rear == -1){           // pushing the first element.
            front = 0; 
            rear = 0; 
            arr[rear] = n;
            return;
        }

        else if((rear == length-1) && (front != 0)){              // rear has gone to the last so we're bringing it to the starting point. 
            rear = 0;
            arr[rear] = n;
        }
        else{                                       //Normal case.
            rear++;
            arr[rear] = n;
        }
    }

    void pop(){
        if(front == -1){                            // empty queue.
            cout<<"queue is empty"<<endl;
        }

        else if(front == rear){     // single element is present so remove it and front = rear = -1 so that we know that queue is empty.
            front = rear = -1;
        }

        else if(front == length - 1){     // front last me pahuch gya hai so bring it to the starting point.
            front = 0;
        }

        else{                       // Normal case.
            front++;
        }
    }
};