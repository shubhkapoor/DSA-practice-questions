/*

https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

*/

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool dfscheck(int node , int parent , int vis[] , vector<int> adj[])
    {
        vis[node] = 1;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfscheck(it , node , vis , adj))
                {
                    return true;
                }
            }
            else if(it != parent)
            {
                return true;
            }
        }
        
        return false;
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        int vis[V] = {0};
        
        for(int i=0 ; i<V ; i++)
        {
            if(!vis[i])
            {
                if(dfscheck(i , -1 , vis , adj))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
