#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map> 
#include<list>
using namespace std;

// cycle detection in directed graphs using BFS.
// https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION

// same as Q5 waali approach lagayenge.

// we can find valid topo sort for only acyclic directed graph so If we're finding a valid topo sort
// that means that this is acyclic else cyclic.


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    // create adjancy list
    unordered_map<int, list<int> > adj; 
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adj[u].push_back(v);
    }

    //find all indegrees
    vector<int> indegree(n);

    for(auto i: adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    // 0 indegree waalo ko push kardo.
    queue<int> q;
    for(int i = 0; i<n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // do bfs
    // count karo number of elements in topo vector
    int count = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        // vector me push karne ki jagah count++ kar do as we don't need the vector.
        count++;

        for(auto i: adj[front]){
            indegree[i]--;
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }
    
    // if count == n then it's a valid topo sort vector.
    if(count == n){
        return false;
    }
    else{
        return true;
    }
}

