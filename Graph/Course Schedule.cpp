/*

https://practice.geeksforgeeks.org/problems/course-schedule/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=course-schedule

*/

class Solution
{
  public:
    vector<int> findOrder(int V, int N, vector<vector<int>> prerequisites) 
    {
        //code here
        
        // Create adjacency list
        vector<int> adj[V];
        
        for(auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        
        // Apply topo sort
        int indegree[V] = {0};
        
        for(int i=0 ; i<V ; i++)
        {
            for(auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0 ; i<V ; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        vector<int> topo;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node])
            {
                indegree[it]--;
                
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        
        if(topo.size() == V) 
        {
            return topo;
        }
        
        return {};
    }
};
