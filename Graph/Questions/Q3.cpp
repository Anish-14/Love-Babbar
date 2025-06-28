#include<iostream>
#include<queue>
#include<unordered_map> 
#include<list>
using namespace std;

// cycle detection in directed graphs using DFS.
// https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// TC O(N+E) number of nodes + edges.
// SC O(N)   number of nodes.

bool iscycle(int node, unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsvisited, unordered_map<int, list<int> > &adj)
{
    visited[node] = true;
    dfsvisited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            bool cycledetected = iscycle(neighbour, visited, dfsvisited, adj);
            if(cycledetected){
              return true;
            }
        }
        // both visited and dfsvisited agar true hai then there is a cycle.
        else if(dfsvisited[neighbour]){
            return true;
        }
    }
    // fuction call se waapas aate waqt ye karna padega accrdng to our plan.
    dfsvisited[node] = false;
    return false;
} 

bool detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {  
    unordered_map<int, list<int> > adj;

    // creating adjacency list iterating through edges.
    // normal tarike se bhi kar skte hai but I found a different way so I included it to the code.
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
    }

    unordered_map<int,bool> visited;
    // made this map to take note of fuction called nodes, agar hum function call se back aa rhe hai after
    // not finding it's neighbours then we'll make the dfsvisited false so that cycle detection works perfectly
    // do some dry run to understand more deeply.
    unordered_map<int,bool> dfsvisited;     

    // 1 se n tak hai node me values, accrdng to the question.
    // if we start with 0 then also it'll work.
    for (int i = 1; i <= n; i++) {
      if (!visited[i]){
          bool cycle = iscycle(i, visited, dfsvisited, adj);
          if(cycle){
            return true;
          }
      }
    }

    return false;
}






