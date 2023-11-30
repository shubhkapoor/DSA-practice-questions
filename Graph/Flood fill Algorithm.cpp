/*

https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm

*/

class Solution {
private:

    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int iniColor, int newColor, int delRow[], int delCol[])
    {
        ans[row][col] = newColor;
        
        int n = image.size();
        int m = image[0].size();
        
        for(int i=0 ; i<4 ; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m) && (ans[nrow][ncol] != newColor) && (image[nrow][ncol]==iniColor))
            {
                dfs(nrow , ncol , ans , image , iniColor , newColor , delRow , delCol);
            }
        }
    }

public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];
        
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        dfs(sr , sc , ans , image , iniColor , newColor , delRow , delCol);
        
        return ans;
    }
};
