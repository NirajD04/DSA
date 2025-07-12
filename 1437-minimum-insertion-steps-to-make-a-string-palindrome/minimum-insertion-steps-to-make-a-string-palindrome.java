class Solution {
    public int minInsertions(String s) {
        return s.length() - LPS(s);
    }

    private int LPS(String s) {
        int n = s.length();
        String t = new StringBuilder(s).reverse().toString();
        int[][] dp = new int[n][n];
        for(int[] row : dp) Arrays.fill(row, -1);

        return LCS(s, t, n - 1, n - 1, dp);
    }

    private int LCS(String s, String t, int i, int j, int[][] dp) {
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s.charAt(i) == t.charAt(j)) return dp[i][j] = 1 + LCS(s, t, i - 1, j - 1, dp);

        return dp[i][j] = Math.max(LCS(s, t, i - 1, j, dp), LCS(s, t, i, j - 1, dp));
    }
}