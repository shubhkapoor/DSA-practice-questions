#include <bits/stdc++.h>
using namespace std;

int main()
{
    // n -> node
    // m -> edges
    
    int n,m;
    
    cin>>n>>m;
    
    // ADJACENCY MATRIX (SPACE COMPLEXITY -> O(N*N)
    int adj[n+1][m+1];
    
    for(int i=0 ; i<m ; i++)
    {
        int u,v;
        
        cin>>u>>v;
        
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // ADJACENCY LIST (SPACE COMPLEXITY -> O(2*EDGE)
    vector<int> adj[n+1];
    
    for(int i=0 ; i<m ; i++)
    {
        int u,v;
        
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}
