#include<iostream>
#include<queue>
#include<unordered_map> 
#include<list>
using namespace std;

// cycle detection in undirected graph.
// https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM



// by BFS traversal, T.C. O(n)
bool isCycle( unordered_map<int, list<int> > &adj, unordered_map<int, bool> &visited, int node){
    
    // we want to keep the track of parent of a node.
    unordered_map<int, int> parent;
    parent[node] = -1;              // first node ke liye koi parent nhi hai isliye -1 daal diya.

    visited[node] = 1;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        for(auto neighbour : adj[frontNode]){
            //this condition is imp, when this condition reaches then the cycle detection confirms in unordered graph.
            if(visited[neighbour] && neighbour != parent[frontNode]){       // this condn is absolutely right.
                return true;
            }
            // nhi to BFS ki tarah uske neighbours ko daalo queue me.
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = frontNode; 
            }
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{

    // creating the adjacent list.
    unordered_map<int, list<int> > adj;
    for(int i = 0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    unordered_map<int, bool> visited;

    // for non continous graph we've to go through all the nodes.
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            bool cycle = isCycle(adj, visited, i);
            if(cycle == 1){
                return "Yes";
            }
        }
    }

    return "No";
}





// by DFS traversal, T.C. O(n)
bool isCycleDFS(unordered_map<int,list<int> > &adj, int parent, unordered_map<int, bool> &visited, int node){
    visited[node] = 1;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            bool cycleDetection = isCycleDFS(adj, node, visited, neighbour);
            if(cycleDetection){
                return true;
            }
        }
        // yaha per aaye that means visited == 1 hai for neighbour. 
        else if(neighbour != parent){
            return true;
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{

    // creating the adjacent list.
    unordered_map<int, list<int> > adj;
    for(int i = 0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            bool cycle = isCycleDFS(adj, -1, visited, i);
            if(cycle == 1){
                return "Yes";
            }
        }
    }

    return "No";
}

















