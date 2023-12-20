/*

https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1

*/

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        
        vector<pair<int,int>> adj[n];
        
        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1] , it[2]});
        }
        
        // { stops , {node , dist} }
        
        queue<pair<int , pair<int,int>>>q;
        vector<int> dist(n , 1e9);
        
        q.push({0 , {src , 0}});
        dist[src] = 0;
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            if(stops>K)
            {
                continue;
            }
            
            for(auto iter : adj[node])
            {
                int adjnode = iter.first;
                int edwt = iter.second;
                
                if(cost+edwt < dist[adjnode] && stops<=K)
                {
                    dist[adjnode] = cost+edwt;
                    q.push({stops+1 , {adjnode , cost+edwt}});
                }
            }
        }
        
        if(dist[dst] == 1e9)
        {
            return -1;
        }
        
        return dist[dst];
    }
};
