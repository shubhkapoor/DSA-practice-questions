/*

https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1

*/

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>> dist(n , vector<int>(m,0));
	    
	    vector<vector<int>> vis(n , vector<int>(m,0));
	    
	    // {row,col,step}
	    queue<pair<pair<int,int> , int>> q;
	    
	    for(int i=0 ; i<n ; i++)
	    {
	        for(int j=0 ; j<m ; j++)
	        {
	            if(grid[i][j] == 1)
	            {
	                q.push({{i,j} , 0});
	                vis[i][j] = 1;
	            }
	            else
	            {
	                vis[i][j] = 0;
	            }
	        }
	    }
	    
	    int drow[] = {-1,0,1,0};
	    int dcol[] = {0,1,0,-1};
	    
	    while(!q.empty())
	    {
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int step = q.front().second;
	        
	        q.pop();
	        dist[row][col] = step;
	        
	        for(int i=0 ; i<4 ; i++)
	        {
	            int nrow = row + drow[i];
	            int ncol = col + dcol[i];
	            
	            if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m) && (vis[nrow][ncol]==0))
	            {
	                vis[nrow][ncol] = 1;
	                q.push({{nrow,ncol} , step+1});
	            }
	        }
	    }
	    
	    return dist;
	}
};
