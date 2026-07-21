class Solution {
public:
void dfs(int r,int c,vector<vector<char>>& grid, vector<vector<bool>>&vis){
      int m = grid.size();
        int n = grid[0].size();
    if(r>=m||c>=n||r<0||c<0){
        return;
    }
    if(grid[r][c]=='0'||vis[r][c]){
        return;
    }
    vis[r][c]=true;
    dfs(r+1,c,grid,vis);
      dfs(r-1,c,grid,vis);
        dfs(r,c+1,grid,vis);
          dfs(r,c-1,grid,vis);

}
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
         int m = grid.size();
        int n = grid[0].size();
      vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
 for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    count++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return count;
    }
};