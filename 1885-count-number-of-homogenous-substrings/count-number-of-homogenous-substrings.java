class Solution {
    public int countHomogenous(String s) {
        int ans = 0;
        int currStreak = 0;
        int MOD = 1_000_000_007;

        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || s.charAt(i) == s.charAt(i - 1)) {
                currStreak++;
            } else {
                currStreak = 1;
            }

            ans = (ans + currStreak) % MOD;
        }

        return ans;
    }
}
