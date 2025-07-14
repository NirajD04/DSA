class Solution {
    public boolean isPalindrome(int i, int j, String s) {
        if (i >= j) {
            return true;
        }
        if (s.charAt(i) == s.charAt(j)) {
            return isPalindrome(i + 1, j - 1, s);
        } else {
            return false;
        }
    }

    public String longestPalindrome(String s) {
        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (isPalindrome(i, j, s)) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substring(start, start + maxLen);
    }
}
