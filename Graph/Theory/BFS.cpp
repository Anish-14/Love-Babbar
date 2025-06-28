#include<iostream>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;
#include "stl1.cpp"

// BFS traversal            breadth first search 
// https://www.naukri.com/code360/problems/bfs-in-graph_973002?leftPanelTabValue=SUBMISSION

// YE WAALA TAREEKA BHI SAME HI HAI BUS ISME ADJACENCY LIST PEHLE SE HI BANAKE DI HAI

// void bfs(vector<int> &ans, unordered_map<int, bool> &visited, vector<vector<int>> &adj, int node){
//     queue<int> q;
//     q.push(node);

//     visited[node] = true;
    
//     while(!q.empty()){
//         int frontNode = q.front();
//         q.pop();
//         ans.push_back(frontNode);

//         for(auto i : adj[frontNode]){
//             // frontNode ke neighbours ko queue me daal diya jo visit nhi hue hai.
//             if(!visited[i]){
//                 q.push(i);
//                 visited[i] = true;
//             }
//         }
//     }
// }



// vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
//     vector<int> ans;
//     unordered_map<int, bool> visited;


//     // USE THIS WHEN YOU ALSO HAVE TO INCLUDE THE DISCONNECTED PARTS OF THE GRAPH.
//     // for(int i = 0; i<n; i++){
//     //     if(!visited[i]){
//     //         bfs(ans, visited, adj, i);
//     //     }
//     // }

//     bfs(ans, visited, adj, 0);
    
//     return ans;
// }




void traversal(unordered_map<int, list<int> > &adjList, unordered_map<int, bool> &visited, vector<int> &answer, int node) {
    queue<int> Q;
    Q.push(node);
    visited[node] = 1;

    while(!Q.empty()) {
        int frontVal = Q.front();
        Q.pop();
        visited[frontVal] = true;
        answer.push_back(frontVal);

        for(auto i : adjList[frontVal]) {
            if(!visited[i]) {
                Q.push(i);
            }
        }
    }
}

vector<int> BFS(int vertex, vector< pair<int, int> > edges) {
    unordered_map<int, list<int> > adjList;
    vector<int> answer;
    unordered_map<int, bool> visited;
    
    // Creating Adjacency List
    // use set instead of list in adj to get the results in sorted way because set gives out values in sorted way
    for(int i=0; i<edges.size( ); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Traversing all components of a graph
    for(int i=0; i<vertex; i++) {
        if(!visited[i]) {
            traversal(adjList, visited, answer, i);
        }
    }

    return answer;
}

int main() {
    int n, m;

    cout << "Enter the number of nodes : ";
    cin >> n;

    cout << "Enter the number of edges : ";
    cin >> m;

    vector< pair<int,int> > edges(m, make_pair(0,0));

    for(int i=0; i<m; i++) {
        cin >> edges[0].first;
        cin >> edges[0].second;
    }

    vector<int> solution = BFS(n, edges);

    cout << "BFS Traversal : ";
    for(auto i : solution) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
