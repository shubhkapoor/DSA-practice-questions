/*

https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states

*/

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        vector<int> adjRev[V];
        int indegree[V] = {0};
        
        for(int i=0 ; i<V ; i++)
        {
            for(auto it : adj[i])
            {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0 ; i<V ; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        vector<int> safeNodes;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            
            for(auto it : adjRev[node])
            {
                indegree[it]--;
                
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        
        sort(safeNodes.begin() , safeNodes.end());
        return safeNodes;
    }
};
