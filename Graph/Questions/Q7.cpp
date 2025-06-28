#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map> 
#include<list>
using namespace std;


// shortest path in an undirected graph.
// https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION

// Approach
// by bfs as bfs stores shortest path
// we made parent map, and bfs will mark parents in fastest manner.
// so we'll access the parent map and we can make the shortest path to any node we want .


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// make adjacency list
    unordered_map<int, list<int> > adj;
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
    // do bfs
    unordered_map<int, int> parent;
    unordered_map<int, bool> visited;
    queue<int> q;

    q.push(s);
    parent[s] = -1;     // -1 for the first node.
    visited[s] = 1;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i:adj[front]){
            if(!visited[i]){
                visited[i] = 1;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    // We've made the parent map succesfully
    // prepare shortest path
    vector<int> ans;
    int currNode = t;           // last node (peeche se start karna padega)
    ans.push_back(currNode);

    while(currNode != s){                   // "s" is the first node 
        currNode = parent[currNode];        // aise karte karte hum first node per pahoch jaayenge.
        ans.push_back(currNode);
    }

    reverse(ans.begin(), ans.end());        // reverse the ans as we saved it backwards.

    return ans;
}



