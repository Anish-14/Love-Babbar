#include<iostream>
#include<queue>
using namespace std;

// queue and its STL implementation.
// follows "FIFO" order "first in first out".

int main(){
    // creating queue
    queue<int> q;

    // push an element 
    q.push(2);
    q.push(6);
    q.push(8);
    q.push(13);

    cout<<q.front()<<endl;      // to access the top/front element of the queue,which will be popped out first.
    cout<<q.back()<<endl;       // to access the back element of the queue(jo last me daala hai).
    // pop an element 
    q.pop();
    cout<<q.front()<<endl; 
    q.pop();
    cout<<q.front()<<endl;   

    //know size of queue
    cout<<q.size()<<endl;

    //check if the queue is empty (this fun gives a bool value)
    cout<<q.empty()<<endl;

}