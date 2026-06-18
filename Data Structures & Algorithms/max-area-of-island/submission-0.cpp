class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    maxIsland = 0;
                    maxIsland = dfs(grid, m, n, i, j);
                    result = max(result, maxIsland);
                }
            }
        }
        return result;
    }

    private:

    int maxIsland = 0;

    int dfs(vector<vector<int>> &grid, int m, int n, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
            return 0;

        grid[i][j] = 0;
        maxIsland++;

        (void)dfs(grid, m, n, i - 1, j);
        (void)dfs(grid, m, n, i + 1, j);
        (void)dfs(grid, m, n, i, j - 1);
        (void)dfs(grid, m, n, i, j + 1);

        return maxIsland;
    }
};
