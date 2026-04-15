class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y, int dist) {
        int m = grid.size(), n = grid[0].size();
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] < dist) return;

        grid[x][y] = dist;

        dfs(grid, x + 1, y, dist + 1);
        dfs(grid, x - 1, y, dist + 1);
        dfs(grid, x, y + 1, dist + 1);
        dfs(grid, x, y - 1, dist + 1);
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    dfs(grid, i, j, 0);
                }
            }
        }
    }
};
