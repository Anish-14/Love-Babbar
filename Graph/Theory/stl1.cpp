#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template <typename T >

class graph{
    public:

    // adjacency list
    unordered_map<T, list<T> > adj;

    void AddEdge(T u, T v, bool direction){
        // direction = 0 -> undirected graph , simply direction nhi hoti inme
        // direction = 1 -> directed graph

        // create an edge from u to v.
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjlist(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<", ";
            }            
            cout<<endl;
        }
    }

};

// Degree of an edge in case of undirected graph is number of edges connected to it
// directed graph -->
// indegree :   kitni edges iski taraf aa rhi hai
// outdegree :  kitni edges isse nikal rhi hai

// Weighted Graph : edges per weights dale huye hai

// path : koi bhi rasta ek graph me bus ye dhyaan rhe ki us raaste me koi bhi node multiple times naa aaye keval 1 baar aaye

// Adjacency vector : ek 2D vector jisme index nodes ko darshate hai and then kon kisse connected hai ye data likha rhta hai
// eg:- let's suppose 3 nodes hai 0,1,2 and 3 edges hai 0->1, 1->2, 2->0 so the adjacency matrix will look like
// 
// 0 1 0        iska matlab 0 is connected to 1        
// 0 0 1        1 is connected to 2. Note : 1 is not connected to 0, because we have assumed it to be a directed graph. If It was an undirected graph then 1 will also be connected to 0
// 1 0 0        2 is connected to 0


// more helpful/used one is adjacency list
// Adjacency list : har node ke liye hum jis jis se vo connected hai uska data save kar lenge
// eg:-  0 -- 1
//       |    | \ 
//       4 -- 3--2
// iski adjcency list will be :- isko both vector and list dono me implement kar skte hai
// 0 -> 1,4
// 1 -> 0,2,3
// 2 -> 1,3
// 3 -> 1,2,4
// 4 -> 0,3








int main(){
    int n;
    cout<<"Enter the number of Nodes"<<endl;
    cin>>n;

    int m; 
    cout<<"Enter the number of Edges"<<endl;
    cin>>m;

    graph<int> g;

    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v; 

        // creating undirected graph.
        g.AddEdge(u,v,0);
    }

    g.printAdjlist();
}