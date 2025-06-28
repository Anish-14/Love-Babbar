#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map> 
#include<list>
using namespace std;


// Topological sort using dfs.(directed acyclic graph per hi use hota hai topo sort)
// https://www.naukri.com/code360/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// In topo sort we want all the nodes in a vector sorted in such a way that for every two nodes
// u,v  v comes in adj list of u, i.e. v jo hai u se pehle aana chahiye.

// Here hum by recursion adj me jaate jaa rhe hai and jab koi khaali adj waala node mil raha hai then
// backtrack karte waqt usko stack me push kar rhe hai taaki sabse last me vo ans me push ho.

// agar hum ek directed graph me valid topological sort nhi nikal paa rhe hai, that means a cycle is present in that graph

void toposort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int> > &adj){
    visited[node] = 1;

    for(auto nbr: adj[node]){
        if(!visited[nbr]){
            toposort(nbr, visited, s, adj);
        }
    }

    // backtrack karte waqt stack me push kar diya.
    s.push(node);
}
 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // create adjancy list
    unordered_map<int, list<int> > adj;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int>s;

    for(int i = 0; i<v; i++){
        if(!visited[i]){
            toposort(i, visited, s, adj);
        }
    }

    // ans me push kar diya stack ko, we wanted reverse order and that's what stack is for.
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}







