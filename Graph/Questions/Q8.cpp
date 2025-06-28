#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map> 
#include<list>
using namespace std;

// shortest path in directed acyclic graphs
// given a source node in a graph mentioned above you have to find the shortest dis for all the other nodes
// from the source node and save it in a vector.
// May contain negative weights.
// lec 94

class Graph{
    public:
    unordered_map<int, list<pair<int,int> > > adj; 

    // adding Edge having weight as well.
    void AddEdge(int u, int v, int weight){
        pair<int, int> p = make_pair(v,weight);
        adj[u].push_back(p);
    }

    void printAdj(){
        for(auto i: adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }cout<<endl;
        }
    }

    // preparing the topo sort stack.
    void dfs(int node, unordered_map<int,bool> &vis, stack<int> &topo ){
        vis[node] = true;
        for(auto neighbor : adj[node]){
            if(!vis[neighbor.first]){ 
                dfs(neighbor.first,vis,topo); 
            }
        }
        topo.push(node);
    }

    // the main algo.
    void getShortestPath(int src, vector<int> &dis, stack<int> topo){
        // mark the source dis to be 0
        dis[src] = 0;

        while(!topo.empty()){
            int top = topo.top();
            topo.pop();

            // agar dis INT_MAX na ho tab process karo because agar dist int_max hai iska matlab vo topo stack me 
            // humare source se upar aata hai and us tak pahocha nhi jaa skta.
            // humne sabko int_max se initialize kiya hai but when we process the source node the hum kuchh nodes ke dis
            // ko change kar dete hai to be further processed as per algo.

            if(dis[top] != INT_MAX){
                // fetch its neighboring nodes
                for(auto i : adj[top]){
                    if(dis[top] + i.second  < dis[i.first]){        // compare the dis, if small then update
                        dis[i.first] = dis[top] + i.second;
                    }
                }
            }
        }
    }
};


int main(){
    Graph g;
    g.AddEdge(0,1,5);
    g.AddEdge(0,2,3);
    g.AddEdge(1,2,2);
    g.AddEdge(1,3,6);
    g.AddEdge(2,3,7);
    g.AddEdge(2,4,4);
    g.AddEdge(2,5,2);
    g.AddEdge(3,4,-1);
    g.AddEdge(4,5,-2);

    g.printAdj();           

    int n = 6;          // for this particular question.

    // Topo sort        we want a linear representation of which node comes before the other.
    unordered_map<int, bool> visited;
    stack<int> s;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            g.dfs(i,visited,s);
        }
    }
    
    // on our way to finding the shortest dis vector.

    int src = 1;         // source node is 1 for this question.
    
    vector<int> dis(n);             

    for(int i = 0; i<n; i++){           // initializing the dis by INT_MAX.
        dis[i] = INT_MAX;
    }

    g.getShortestPath(src,dis,s);

    cout<<"answer is: "<<endl;

    for(int i = 0; i<n; i++){
        cout<<dis[i]<<" ";
    }cout<<endl;


    // printing the stack it should be 0,1,2,3,4,5 for this particular question.

    // while(!s.empty()){
    //     int top = s.top();
    //     cout<<top<<",";
    //     s.pop();
    // }
    // cout<<endl;

}