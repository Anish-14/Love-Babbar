#include<iostream>
#include<stack>
using namespace std;

// in this question we have to insert the given integer on bottom of given int stack.

void printStack(stack<int> a){           // function for printing the stack.
    if(a.empty()){
        return;
    }
    cout<<a.top()<<endl;
    a.pop();
    printStack(a);
}

void insertAtBottom(stack<int> &a, int n){
    if(a.empty()){                       // agar khali hua to hum apna integer fill kar denge.
        a.push(n);
        return;
    }

    int currentTop = a.top();       // saving the top element cause we're going to pop it.
    a.pop();

    insertAtBottom(a,n);           // recalling the fun till we get the empty list and push our integer.

    a.push(currentTop);             // backtracking 
    return;
}

int main(){
    stack<int> a;
    a.push(3);
    a.push(4);
    a.push(7);
    a.push(8);

    //printStack(a);
    int n = 9;
    insertAtBottom(a,n);

    printStack(a);

    return 0;
}