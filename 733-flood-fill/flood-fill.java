public class Solution {

    int m, n;

    int[][] dirs = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };


    private void dfs(int[][] image, int r, int c, int origColor, int newColor) {
      
        if (r < 0 || r >= m || c < 0 || c >= n || image[r][c] != origColor) {
            return;
        }

        
        image[r][c] = newColor;

        
        for (int[] d : dirs) {
            dfs(image, r + d[0], c + d[1], origColor, newColor);
        }
    }



    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        m = image.length;
        n = image[0].length;
        int origColor = image[sr][sc];
        

        if (origColor != newColor) {
            dfs(image, sr, sc, origColor, newColor);
        }
        return image;
    }
}