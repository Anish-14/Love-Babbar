#include<iostream>
#include<queue>
using namespace std;

// here we have given an array filled with integer,a integer specifying the size of arr, and a integer telling us what the size of group will be.
// we have to make a group of k in array and print the FIRST NEGATIVE NUMBER that comes in that group.
// It is correct sol as I have verified it.

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K){
    
    deque<long long int> dq;
    vector<long long> ans;
    
    // storing the first K box's negative element.
    for(int i = 0; i<K; i++){
        if(A[i]<0){
            dq.push_back(i);
        }
    }
    
    // storing the answer
    if(dq.size() >0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    
    // other element of array.
    for(int i = K; i<N; i++){
        // popping an element
        if(!dq.empty()  && i - dq.front() >= K){
            dq.pop_front();
        }
        // pushing an element
        if(A[i]<0){
            dq.push_back(i);
        }
        
        // storing ans.
        if(dq.size() >0){
        ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        
    }
    return ans;
 }