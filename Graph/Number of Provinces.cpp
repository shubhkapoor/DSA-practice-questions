/*

https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces

*/


class Solution {
  private:
    void dfs(int node , vector<int> adjls[] , int vis[])
    {
        vis[node] = 1;
        
        for(auto it : adjls[node])
        {
            if(!vis[it])
            {
                dfs(it , adjls , vis);
            }
        }
    }
    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        //creating adjacency list
        
        vector<int> adjls[V];
        
        for(int i=0 ; i<V ; i++)
        {
            for(int j=0 ; j<V ; j++)
            {
                if(adj[i][j]==1 && i!=j)
                {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        
        int count=0;
        int vis[V] = {0};
        
        for(int i=0 ; i<V ; i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i , adjls , vis);
            }
        }
        
        return count;
    }
};
