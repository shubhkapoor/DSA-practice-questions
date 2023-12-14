/*

https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix

*/

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
      
        set<pair<int,int>> st;
        
        vector<int> dist(V , 1e9);
        
        dist[S] = 0;
        st.insert({0,S});
        
        while(!st.empty())
        {
            auto it = *(st.begin());
            
            int dis = it.first;
            int node = it.second;
            
            st.erase(it);
            
            for(auto it : adj[node])
            {
                int edgwt = it[1];
                int adjnode = it[0];
                
                if(dis + edgwt < dist[adjnode])
                {
                    if(dist[adjnode] != 1e9)
                    {
                        st.erase({dist[adjnode] , adjnode});
                    }
                    
                    dist[adjnode] = dis + edgwt;
                    
                    st.insert({dist[adjnode] , adjnode});
                }
            }
        }
        
        return dist;
    }
};
