class Solution {
public:
    vector<vector<int>> direction{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(vector<vector<int>>& ans, int row, int col, int intialcolor,
             int color) {

        if (row < 0 || row >= ans.size() || col < 0 || col >= ans[0].size() ||
            ans[row][col] != intialcolor)
            return;

        ans[row][col] = color;

        for (auto dir : direction) {
            int new_row = row + dir[0];
            int new_col = col + dir[1];

            dfs(ans, new_row, new_col, intialcolor, color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        vector<vector<int>> ans = image;
        int intialcolor = ans[sr][sc];

        if (intialcolor != color) {
            dfs(ans, sr, sc, intialcolor, color);
        }
        return ans;
    }
};