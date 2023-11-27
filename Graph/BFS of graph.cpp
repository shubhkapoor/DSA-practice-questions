/*

https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph

*/

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int n, vector<int> adj[])
    {
        // Code here

        vector<int> bfs;
        queue<int> q;
        int vis[n] = {0};
        vis[0] = 1;
        q.push(0);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            bfs.push_back(node);

            for(auto it : adj[node])
            {
                if(!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return bfs;
    }
};
