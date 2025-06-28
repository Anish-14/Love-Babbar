#include<iostream>
#include<stack>
using namespace std;

// In this question we have to remove the middle element of stack keeping all thing exactly the same.

void printStack(stack<int> s,int a){
    for(int i = 0; i<a; i++){
        cout<<s.top()<<endl;
        s.pop();
    }
    return;
}



void removeMiddleElement(stack<int> *s, int a ){
    int middle = (a+1)/2;
    stack<int> temp;
    for(int i = 1; i<middle; i++){
        int top = s->top();
        temp.push(top);
        s->pop();
    }
    
    s->pop();


    for(int i = 1; i<middle; i++){
        int top = temp.top();
        s->push(top);
        temp.pop();
    }

    return;
}

int main (){
    stack<int> s;
    int a = 5;

    s.push(3);
    s.push(5);
    s.push(9);
    s.push(4);
    s.push(2);

    printStack(s,a);
    cout<<endl;

    removeMiddleElement(&s,a);
    printStack(s,a);

 
}



// love babbar's way (recursion)


// void solve(stack<int>&inputStack, int count, int size) {
//     //base case
//     if(count == size/2) {       // jab tak middle element na pahoche tab tak pop
//         inputStack.pop();
//         return ;
//     }
    
//     int num = inputStack.top();         // save the popped number.
//     inputStack.pop();
    
// 	//RECURSIVE CALL
//     solve(inputStack, count+1, size);
    
//     inputStack.push(num);               // push the elements back in the stack.
    
// }

// void deleteMiddle(stack<int>&inputStack, int N){
	
//     int count = 0;
//     solve(inputStack, count, N);
   
// }













