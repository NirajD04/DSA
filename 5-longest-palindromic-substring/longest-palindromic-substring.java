class Solution {
    public boolean isPalindrome(int i, int j, String s) {
        while(i<j){
            if(s.charAt(i)!= s.charAt(j)){
                return false;
            }
            i++;
            j--;
        }
        return true;
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

        return s.substring(start,  start+maxLen);
    }
}
