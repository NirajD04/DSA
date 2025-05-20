class Solution {
public:
    vector<vector<int>> direction{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int m, n;

    int result = 0;
    int nonobstacles = 0;

    void solve(vector<vector<int>>& grid, int x, int y, int count) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == -1) {
            return;
        }

        if (grid[x][y] == 2) {
            if (count == nonobstacles) {
                result++;
            }
            return;
        }

        grid[x][y] = -1;

        for (auto dir : direction) {
            int nx = x + dir[0];
            int ny = y + dir[1];

            solve(grid, nx, ny, count + 1);
        }

        grid[x][y] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int start_x = 0;
        int start_y = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    nonobstacles++;
                }
                if (grid[i][j] ==1) {
                    start_x = i;
                    start_y = j;
                }
            }
        }

        nonobstacles +=1;
        int count = 0;
        solve(grid, start_x, start_y, count);
        return result;
    }
};
