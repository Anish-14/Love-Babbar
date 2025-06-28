#include<iostream>
using namespace std;
#include<queue>

// GFG (in queue section)
// Interleave the First Half of the Queue with Second Half
// 1 2 3 4 5 6  agar input hai to isko half me tod do. 1 2 3  && 4 5 6  now pehle first waale se ek uthao
// then agle waale se so ans would be 1 4 2 5 3 6 .

vector<int> rearrangeQueue(queue<int> &q){
        
        vector<int> ans;
        int N = q.size();
        
        queue<int> p;
        for(int i = 0; i<N/2; i++)
        {
            int val = q.front();
            q.pop();
            p.push(val);
        }
        
        for(int i = 0; i<N/2; i++){
            ans.push_back(p.front());
            p.pop();
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }

int main(){
    
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    vector<int> sol;

    sol = rearrangeQueue(q);

    for(int i = 0; i<sol.size(); i++){
        cout<<sol[i]<<" ";
    }
}


 
// // If there is a codition that only stack can be used as an auxillary space.
// class Solution{
//     void fillStack(queue<int> &q, stack<int> &s, int n){
//         if(n <= 0){
//             return;
//         }
        
//         int val = q.front();
//         q.pop();
//         fillStack(q,s,--n);
//         s.push(val);
//     }
// public:
//     vector<int> rearrangeQueue(queue<int> &q){
        
//         vector<int> ans;
//         int N = q.size();
        
//         stack<int> s;
//         fillStack(q,s,N/2);
        
//         for(int i = 0; i<N/2; i++){
//             ans.push_back(s.top());
//             s.pop();
//             ans.push_back(q.front());
//             q.pop();
//         }
        
//         return ans;
//     }
// };