class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Directions for 8 neighbors
        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1},
                                             {0, -1},  {0, 1},  {1, -1},
                                             {1, 0},   {1, 1}};

        // Make a copy of the board
        vector<vector<int>> copy = board;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                int liveNeighbors = 0;

                // Count live neighbors
                for (auto dir : directions) {
                    int r = i + dir.first;
                    int c = j + dir.second;

                    if (r >= 0 && r < m && c >= 0 && c < n && copy[r][c] == 1) {
                        liveNeighbors++;
                    }
                }

                // Apply the rules
                if (copy[i][j] == 1) {
                    
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        board[i][j] = 0; // Dies
                    } else {
                        board[i][j] = 1; // Lives
                    }
                } else {
                    if (liveNeighbors == 3) {
                        board[i][j] = 1; // Becomes live
                    } else {
                        board[i][j] = 0; // Remains dead
                    }
                }
            }
        }
    }
};
