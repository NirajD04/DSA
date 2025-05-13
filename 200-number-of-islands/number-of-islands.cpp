class Solution {
public:
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>>& grid, int i, int j) {

        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] != '1') {
            return;
        }

        grid[i][j] = '0'; // mark as visited

        for (auto& dir : direction) {
            int newrow = i + dir[0];
            int newcol = j + dir[1];
            dfs(grid, newrow, newcol);
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int numIslands = 0;

        for (int i = 0; i < grid.size(); i++) {

            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] == '1') {
                    numIslands++;
                    dfs(grid, i, j);
                }
            }
        }

        return numIslands;
    }
};
