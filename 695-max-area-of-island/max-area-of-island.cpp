class Solution {
public:
int dfs(vector<vector<int>>& grid,int m,int n,int i,int j,vector<vector<bool>>& vis){
    if(i>=m||j>=n||i<0||j<0){
        return 0;
    }
    if(grid[i][j]==0||vis[i][j]){
        return 0;
    }
    vis[i][j]=true;

    return 1+ dfs(grid,m,n,i+1,j,vis)+dfs(grid,m,n,i-1,j,vis)+ dfs(grid,m,n,i,j+1,vis)+dfs(grid,m,n,i,j-1,vis);

    
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
  
        int m=grid.size();
        int n=grid[0].size();
           vector<vector<bool>> vis(m, vector<bool>(n, false));
              int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]==1&&!vis[i][j]){
              
               int num= dfs(grid,m,n,i,j,vis);
                count=max(count,num);
               }
            }
        }
        return count;
    }
};