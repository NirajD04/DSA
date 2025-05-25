class Solution {
public:
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int maxsum = 0;

    void dfs(vector<vector<int>>& grid, int i, int j, int& sum) {

        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] != 1) {
            return;
        }
        sum += 1;
        grid[i][j] = 0; // mark as visited

        for (auto& dir : direction) {
            int newrow = i + dir[0];
            int newcol = j + dir[1];
            dfs(grid, newrow, newcol, sum);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int sum = 0;
        for (int i = 0; i < grid.size(); i++) {

            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] == 1) {
                    sum = 0;
                    dfs(grid, i, j, sum);
                    maxsum = max(maxsum, sum);
                }
            }
        }

        return maxsum;
    }
};