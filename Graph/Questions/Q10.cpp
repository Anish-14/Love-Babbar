#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map> 
#include<list>
using namespace std;

// min spanning tree
// prim's algo
// https://www.naukri.com/code360/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // create adj list
    unordered_map<int, list<pair<int, int> > > adj;
    for(int i = 0; i<g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    // creating useful and needed DS.
    vector<int> key(n+1);
    vector<bool> mst(n+1); 
    vector<int> parent(n+1);

    // initializing them
    for(int i = 0; i<=n; i++){
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1; 
    }

    // starting the algo
    key[1] = 0;
    parent[1] = -1;

    for(int i = 1; i<=n; i++){
        int mini = INT_MAX;
        int u;
        // find min waali node
        for(int j = 1; j<=n; j++){
            if(mst[j] == false && key[j] < mini){
                u = j;
                mini = key[j];
            }
        }

        // mark min node as true
        mst[u] = true;

        //check its adjacent nodes
        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    //  i = 2 se isliye start kiya because 1 ke liye parent -1 tha and we didn't want to submit our answer in that way
    // this totally depends on the platform you're submitting the code

    vector<pair<pair<int, int >, int > > result;
    for(int i = 2; i<=n; i++){
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}





