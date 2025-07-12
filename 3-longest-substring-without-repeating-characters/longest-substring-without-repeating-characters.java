class Solution {
    public int lengthOfLongestSubstring(String s) {
        int l = 0;
        int r = 0;

        int n = s.length();

        int count = 0;

        HashMap<Character, Integer> mp = new HashMap();

        while (r < n) {

            char chright= s.charAt(r);
            mp.put(chright, mp.getOrDefault(chright, 0) + 1);

            while (mp.get(chright) > 1) {
                char chleft = s.charAt(l);
                mp.put(chleft, mp.getOrDefault(chleft, 0) - 1);

                l++;
            }

            count = Math.max(count, r - l + 1);
            r++;
        }

        return count;
    }
}