/*

https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges

*/

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        //row
        int n = grid.size();
        
        //col
        int m = grid[0].size();
        
        //{row,col,time}
        queue<pair <pair<int,int> , int>> q;
        
        int vis[n][m];
        int cntFresh = 0;
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else
                {
                    vis[i][j] = 0;
                }
                
                if(grid[i][j]==1)
                {
                    cntFresh++;
                }
            }
        }
        
        int tm=0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        int cnt = 0;
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            
            q.pop();
            
            tm = max(tm,t);
            
            for(int i=0 ; i<4 ; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                    
                if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m) && (grid[nrow][ncol]==1) && (vis[nrow][ncol]!=2))
                {
                    q.push({{nrow,ncol} , t+1 });
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
        
        if(cntFresh!=cnt)
        {
            return -1;
        }
        
        return tm;
    }
};
