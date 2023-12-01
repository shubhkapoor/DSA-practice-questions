/*

https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph

*/

class Solution {
    
private:
    
    bool check(int start , int n , int color[] , vector<int>adj[])
    {
        color[start] = 0;
        queue<int> q;
        q.push(start);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node])
            {
                if(color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node])
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    int color[V];
	    
	    for(int i=0 ; i<V ; i++)
	    {
	        color[i] = -1;
	    }
	    
	    for(int i=0 ; i<V ; i++)
	    {
	        if(color[i]==-1)
	        {
	            if(check(i , V , color , adj) == false)
	            {
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

};
