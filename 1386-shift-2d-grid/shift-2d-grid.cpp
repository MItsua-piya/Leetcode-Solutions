class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        while (k--) {
            vector<vector<int>> temp = grid;

          
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n - 1; j++) {
                    temp[i][j + 1] = grid[i][j];
                }
            }

           
            for (int i = 0; i < m - 1; i++) {
                temp[i + 1][0] = grid[i][n - 1];
            }

     
            temp[0][0] = grid[m - 1][n - 1];

            grid = temp;
        }

        return grid;
    }
};