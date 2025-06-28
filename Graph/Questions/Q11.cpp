#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<unordered_map> 
#include<list> 
using namespace std;

// Kruskal's algo
// min spanning tree
// https://www.naukri.com/code360/problems/minimum-spanning-tree_631769?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION



bool cmp(vector<int> &a, vector<int> &b){
  return a[2] < b[2];  
}

void makeSet(vector<int> &parent, vector<int> &rank, int n){
  for(int i = 0; i<n; i++){
    rank[i] = 0;
    parent[i] = i;
  }
}

int findParent(vector<int> &parent, int node){ 
  if(parent[node] == node){
    return node;
  }

  return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int>& parent, vector<int> &rank){
  u = findParent(parent, u);
  v = findParent(parent, v);

  if(rank[u] < rank[v]){
    parent[u] = v;              // we don't increase the rank as the rank is the height/depth of the tree not the breadth or number of nodes attached to it
    // rank[v]++;
  }
  else if(rank[u] > rank[v]){
    parent[v] = u;
    // rank[u]++;
  }
  else{
    parent[u] = v;
    rank[v]++;  
  }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  sort(edges.begin(), edges.end(), cmp);

  vector<int> parent(n);
  vector<int> rank(n);
  makeSet(parent, rank, n);

  int minWeight = 0;

  for(int i = 0; i<edges.size(); i++){
    int u = findParent(parent, edges[i][0]);
    int v = findParent(parent, edges[i][1]);
    int wt = edges[i][2];

    if(u != v){
      minWeight += wt;
      unionSet(u,v,parent,rank); 
    }
  }

  return minWeight;
}

