class Solution {
public:
    vector<vector<int>> direction{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int m, n;
    void dfs(vector<vector<char>>& board, int i, int j,
             vector<vector<bool>>& visited) {
        visited[i][j] = true;

        for (auto dir : direction) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if (ni < m && ni >= 0 && nj < n && nj >= 0 &&
                board[ni][nj] == 'X' && !visited[ni][nj]) {
                dfs(board, ni, nj, visited);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X' && visited[i][j] == false) {
                    dfs(board, i, j, visited);
                    count++;
                }
            }
        }
        return count;
    }
};