#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


// creating and printing 
// we have to print the adjacent matrix of a graph.
// https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

// vector v(N) creates a vector of integers with size N. This means that the vector v will have N elements, all initialized to the default value of the integer type (0).
// On the other hand, vector v [N] creates an array of N vectors. This means that you have an array of vectors, where each vector can have its own size and elements.
// In summary, vector v(N) creates a single vector of size N, while  vector v [N] creates an array of N vectors.


class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // V is the number of nodes
        // edges contains the two int that are adjacent to each other, from their we'd know how many edges are there.
        vector<vector<int> > ans(V);
        // vector<int> ans[V];                // I can write this also and It'll work because of the logic written in the 3 commented lines at very start 
        for(int i = 0; i<edges.size(); i++){
           int u = edges[i].first;
           int v = edges[i].second;

           ans[u].push_back(v);
           ans[v].push_back(u);
        }

        return ans;
    }
};




