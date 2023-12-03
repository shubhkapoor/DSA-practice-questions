/*

https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states

*/

class Solution {
    
  private:
    bool dfs(int node , int vis[] , int pathvis[] , int check[] , vector<int> adj[])
    {
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,pathvis,check,adj)==true)
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathvis[it])
            {
                check[node] = 0;
                return true;
            }
        }
        
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
    
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        int vis[V] = {0};
        int pathvis[V] = {0};
        int check[V] = {0};
        vector<int> safeNodes;
        
        for(int i=0 ; i<V ; i++)
        {
            if(!vis[i])
            {
                dfs(i, vis, pathvis, check, adj);
            }
        }
        
        for(int i=0 ; i<V ; i++)
        {
            if(check[i] == 1)
            {
                safeNodes.push_back(i);
            }
        }
        
        return safeNodes;
    }
};
