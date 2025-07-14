class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;

        HashMap<Character, Integer> hp1 = new HashMap<>();
        HashMap<Character, Integer> hp2 = new HashMap<>();

        for (char c : s.toCharArray()) {
            hp1.put(c, hp1.getOrDefault(c, 0) + 1);
        }

        for (char c : t.toCharArray()) {
            hp2.put(c, hp2.getOrDefault(c, 0) + 1);
        }

        return hp1.equals(hp2);
    }
}
