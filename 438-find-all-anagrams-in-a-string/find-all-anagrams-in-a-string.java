class Solution {
    public boolean allZero(int[] count) {
        for (int num : count) {
            if (num != 0) {
                return false;
            }
        }
        return true;
    }

    public List<Integer> findAnagrams(String s, String p) {
        int k = p.length();  // pattern length
        int[] count = new int[26];  // frequency of characters in p

        for (char ch : p.toCharArray()) {
            count[ch - 'a']++;
        }

        int i = 0, j = 0;
        int n = s.length();

        List<Integer> result = new ArrayList<>();

        while (j < n) {
            count[s.charAt(j) - 'a']--;  // add current char in window

            if (j - i + 1 == k) {
                if (allZero(count)) {
                    result.add(i);  // store start index of valid anagram
                }
                count[s.charAt(i) - 'a']++;  // remove leftmost char from window
                i++;  // slide window
            }

            j++;
        }

        return result;
    }
}
