class Solution {
public:
    int m, n;
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<int>>& ans, int r, int c, int intialcolor,
             int color) {
        if (r < 0 || r >= m || c < 0 || c >= n || ans[r][c] != intialcolor)
            return;

        ans[r][c] = color;

        for (auto dir : direction) {
            int x = r + dir[0];
            int y = c + dir[1];
            dfs(ans, x, y, intialcolor, color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> ans = image;

        m = ans.size();
        n = ans[0].size();

        int intialcolor = ans[sr][sc];

        if (intialcolor != color) {
            dfs(ans, sr, sc, intialcolor, color);
        }
        return ans;
    }
};