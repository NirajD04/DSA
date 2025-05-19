class Solution {
public:
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || row >= board.size() || col < 0 ||
            col >= board[0].size() || board[row][col] != 'O')
            return;

        board[row][col] = 'T'; // Temporarily mark as visited and safe

        for (auto dir : direction) {
            int new_row = row + dir[0];
            int new_col = col + dir[1];
            dfs(board, new_row, new_col);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        
        int n = board[0].size();

        // Step 1: Mark border-connected 'O's

     
        for (int j = 0; j < n; ++j) {   // first and last row
            
            if (board[0][j] == 'O')
                dfs(board, 0, j);

            if (board[m - 1][j] == 'O')
                dfs(board, m - 1, j); 
        }   

        for (int i = 0; i < m; ++i) { // first and last col;
            if (board[i][0] == 'O')
                dfs(board, i, 0);

            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }

        // Step 2: Flip all remaining 'O' to 'X', and revert 'T' back to 'O'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
