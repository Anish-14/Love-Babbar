#include<iostream>
using namespace std;


/*

int main(){
    // stack initialization
    stack<int> s;

    // stack operations
    s.push(3);
    s.push(4);
    s.push(5);

    s.pop();

    cout<<"top element in stack"<<" "<<s.top()<<endl; // 4 as 5 is popped out.

    cout<<s.empty()<<endl;

}

*/



// implemantation of stack on our own.
class OurStack{
public:

    int *arr;
    int top; 
    int size;


    OurStack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int a ){
        if(size - top > 1){
            top++;
            arr[top] = a;
        }

        else{
            cout<<"stack overflow"<<endl;
        }

    }

    void isEmpty(){
        if(top == -1){
            cout<<"stack is Empty"<<endl;
        }
        else{
            cout<<"stack is not Empty"<<endl;
        }
    }

    void pop(){
        if(top == -1){
            cout<<"stack underflow"<<endl;
        }
        else{
            top--;
        }
    }

    void peek(){
        if(top == -1){
            cout<<"stack underflow"<<endl;
        }
        else{
            cout<<"the peek element is : "<< arr[top] <<endl;
        }
    }

    void printStack(){

        if(top == -1){
            cout<<"stack is empty"<<endl;
        }

        int faketop = top;

        while(faketop != -1){
            cout<<arr[faketop]<<endl;
            faketop--; 
        }
    }

};

int main(){

    OurStack s(5);

    s.push(3);
    s.push(5);
    s.push(7);
    s.push(9);
    s.push(1);

    s.printStack();
    cout<<endl;

    s.pop();
    s.printStack();
    cout<<endl;

    s.isEmpty();
    cout<<endl;

    s.peek();

}