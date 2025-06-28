#include<iostream>
#include<stack>
using namespace std;

// we have to reverse the stack using recursion.

void printStack(stack<int> a){           
    if(a.empty()){                  // function for printing the stack.
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

void reverseStack(stack<int> &a){
    if(a.empty())
    {
        return;
    }

    int top = a.top();
    a.pop();

    reverseStack(a);

    insertAtBottom(a,top);
}

int main(){
    stack<int> a;
    a.push(3);
    a.push(4);
    a.push(7);
    a.push(8);

    printStack(a);
    cout<<endl;
    reverseStack(a);
    cout<<endl;
    printStack(a);

}