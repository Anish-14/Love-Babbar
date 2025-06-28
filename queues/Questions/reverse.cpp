#include<iostream>
#include<queue>
using namespace std;

// reverse the given queue.

void reverse(queue<int> q){
    if(q.Empty()){
        return;
    }

    int CurrElement = q.front();
    q.pop();

    reverse(q);

    q.push(CurrElement);
} 

// there are many ways to solve this particular question, one is to save the elements in stack and 
// popping them out and pushing them in queue.