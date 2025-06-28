#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map> 
#include<list>
using namespace std;


// Dijkstra's algorithm
// shortest path in undirected graphs.
// https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


// to understand this code please focus on the maps and its components.
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // create adjacency list
    unordered_map<int, list<pair<int,int> > > adj;
    for(int i = 0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
        
    }

    // creation of distance array
    vector<int> dis(vertices);
    for(int i = 0; i<vertices; i++){
        dis[i] = INT_MAX;
    }

    set<pair<int,int> >st;

    dis[source] = 0;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        // fetch the top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int node = top.second;

        // remove the record now
        st.erase(st.begin());

        // traverse all the neighbours
        for(auto neighbour : adj[node]){
            if(nodeDistance + neighbour.second < dis[neighbour.first]){
                // search ki kahi set me pehle se ye entry to nhi
                auto record = st.find(make_pair(dis[neighbour.first], neighbour.first));
                // if record found then delete it.
                if(record != st.end()){
                    st.erase(record);
                }
                // now insert it again with updated distance
                dis[neighbour.first] = nodeDistance + neighbour.second;
                st.insert(make_pair(dis[neighbour.first], neighbour.first));
            }
        }
    }
    return dis;
}


