class Solution {
    public void gameOfLife(int[][] board) {
        int m = board.length;
        int n = board[0].length;

        // All 8 directions
        int[][] directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };

        // Create a deep copy of the board
        int[][] copy = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                copy[i][j] = board[i][j];
            }
        }

        // Process each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int liveNeighbors = 0;

                for (int[] dir : directions) {
                    int r = i + dir[0];
                    int c = j + dir[1];

                    if (r >= 0 && r < m && c >= 0 && c < n && copy[r][c] == 1) {
                        liveNeighbors++;
                    }
                }

                // Apply Game of Life rules
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
}
