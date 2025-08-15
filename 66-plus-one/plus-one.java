class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        int i = n - 1;

        while (i >= 0) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits; // No carry needed
            }
            digits[i] = 0; // Carry over
            i--;
        }

        // If we reach here, all digits were 9 (like 999 → 1000)
        int[] result = new int[n + 1];
        result[0] = 1; // First digit is 1, rest default to 0
        return result;
    }
}
