#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map> 
#include<list>
using namespace std;


// Topo sort using "Kahn's algo". using BFS.
// https://www.naukri.com/code360/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


// Here hum sabki indegree banayenge, jisme ek node ko kitne log point kar rhe hai ye save hota hai.
// jiska indegree 0 hai usko push kar do queue me, and jaise jaise nodes remove ho rhi hai vaise vaise indegree ko update karte rho.
// jo jo remove kar rhe ho usko ans me save karte jaao.

 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    // create adjancy list
    unordered_map<int, list<int> > adj; 
    for(int i = 0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //find all indegrees
    vector<int> indegree(v);

    for(auto i: adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    // 0 indegree waalo ko push kardo.
    queue<int> q;
    for(int i = 0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // do bfs
    vector<int>ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto i: adj[front]){
            indegree[i]--;
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }
    return ans;
}













