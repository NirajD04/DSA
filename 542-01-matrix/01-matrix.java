import java.util.*;

public class Solution {

    int[][] dir = { {1, 0}, {0, 1}, {0, -1}, {-1, 0} }; // 4 directions
    int m, n;

    public int[][] updateMatrix(int[][] mat) {
        m = mat.length;
        n = mat[0].length;

        Queue<int[]> q = new LinkedList<>();
        int[][] dist = new int[m][n];

        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE); // fill with infinity
        }

        // Add all 0s to the queue and set their distance to 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.offer(new int[]{i, j});
                }
            }
        }

        // BFS traversal
        while (!q.isEmpty()) {
            int[] cell = q.poll();
            int row = cell[0];
            int col = cell[1];

            for (int[] d : dir) {
                int newRow = row + d[0];
                int newCol = col + d[1];

                
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                    dist[newRow][newCol] > dist[row][col] + 1) {

                    dist[newRow][newCol] = dist[row][col] + 1;
                    q.offer(new int[]{newRow, newCol});
                }
            }
        }

        return dist;
    }
}