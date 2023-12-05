/*

https://www.geeksforgeeks.org/problems/alien-dictionary/1

*/

class Solution{
    
    private:
    
    vector<int> topoSort(int v , vector<int> adj[])
    {
        int indegree[v] = {0};
        
        for(int i=0 ; i<v ; i++)
        {
            for(auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0 ; i<v ; i++)
        {
            if(indegree[i] == 0)
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
        
        return topo;
    }
    
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        
        vector<int> adj[K];
        
        for(int i=0 ; i<N-1 ; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.length() , s2.length());
            
            for(int j=0 ; j<len ; j++)
            {
                if(s1[j] != s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        
        vector<int> topo = topoSort(K , adj);
        string ans = "";
        
        for(auto it  :topo)
        {
            ans = ans + char(it + 'a');
        }
        
        return ans;
    }
};
