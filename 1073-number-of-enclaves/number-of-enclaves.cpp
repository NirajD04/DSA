class Solution {
public:
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<int>>& grid, int i, int j) {

        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] != 1) {
            return;
        }

        grid[i][j] = 0; // mark as visited

        for (auto& dir : direction) {
            int newrow = i + dir[0];
            int newcol = j + dir[1];
            dfs(grid, newrow, newcol);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            // First column.
            if (grid[i][0] == 1) {
                dfs(grid, i, 0);
            }
            // Last column.
            if (grid[i][n - 1] == 1) {
                dfs(grid, i, n - 1);
            }
        }

        for (int i = 0; i < n; ++i) {
            // First row.
            if (grid[0][i] == 1) {
                dfs(grid, 0, i);
            }
            // Last row.
            if (grid[m - 1][i] == 1) {
                dfs(grid, m - 1, i);
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    count += 1;
                }
            }
        }

        return count;
    }
};