/*

https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

*/

class Solution {
  private:
    
    bool detectCycle(int node , int parent , int vis[] , vector<int> adj[])
    {
        vis[node] = 1;
        
        for(auto adjnode : adj[node])
        {
            if(!vis[adjnode])
            {
                vis[adjnode] = 1;
                
                if(detectCycle(adjnode , node , vis , adj))
                {
                    return true;
                }
            }
            else if(adjnode != parent)
            {
                return true;
            }
        }
        
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        int vis[V] = {0};
        
        for(int i=0 ; i<V; i++)
        {
            if(!vis[i])
            {
                if(detectCycle(i , -1 , vis , adj))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
