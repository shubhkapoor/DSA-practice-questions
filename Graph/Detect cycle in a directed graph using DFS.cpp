/*

https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

*/

class Solution {

  private:
    bool dfsCheck(int node , int vis[] , int pathvis[] , vector<int> adj[])
    {
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfsCheck(it,vis,pathvis,adj) == true)
                {
                    return true;
                }
            }
            else if(pathvis[it]==1)
            {
                return true;
            }
        }
        
        pathvis[node] = 0;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        int vis[V] = {0};
        int pathvis[V] = {0};
        
        for(int i=0 ; i<V ; i++)
        {
            if(!vis[i])
            {
                if(dfsCheck(i,vis,pathvis,adj) == true)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
