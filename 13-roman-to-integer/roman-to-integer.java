class Solution {
    public int romanToInt(String s) {
        int ans = 0;

        Map<Character, Integer> mp = new HashMap<>();
        mp.put('I', 1);
        mp.put('V', 5);
        mp.put('X', 10);
        mp.put('L', 50);
        mp.put('C', 100);
        mp.put('D', 500);
        mp.put('M', 1000);

        for (int i = 0; i < s.length(); i++) {
            // Check for subtractive cases like IV, IX, etc.
            if (i < s.length() - 1 && mp.get(s.charAt(i)) < mp.get(s.charAt(i + 1))) {
                ans -= mp.get(s.charAt(i));  // subtract if smaller before larger
            } else {
                ans += mp.get(s.charAt(i));  // else just add normally
            }
        }

        return ans;
    }
}
