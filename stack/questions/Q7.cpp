#include<iostream>
#include<stack>
using namespace std;

// sort the stack.

void printStack(stack<int> a){           
    if(a.empty()){                  // function for printing the stack.
        return;
    }
    cout<<a.top()<<endl;
    a.pop();
    printStack(a);
}

void insertAcurately(stack<int> &a, int top){
    if(a.empty()){
        a.push(top);
        return;
    }

    while(!a.empty()){
        int w = a.top();
        if(top >= w)
        {
            a.push(top);
        }
        else
        {
            a.pop();
            insertAcurately(a,top);
            a.push(w);
        }

        return;
    }
}

void sortStack(stack<int> &a){
    if(a.empty()){
        return;
    }

    int top = a.top();
    a.pop();
    
    sortStack(a);

    insertAcurately(a,top);
}

int main(){
    stack<int> a;
    a.push(15);
    a.push(27);
    a.push(32);
    a.push(8);

    printStack(a);
    cout<<endl;
    sortStack(a);
    cout<<endl;
    printStack(a);

}