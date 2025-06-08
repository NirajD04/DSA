class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int countOne = 0;  // number of 1's seen so far (left side)
        int minFlips = 0;  // flips needed

        for (char ch : s) {
            if (ch == '0') {
                // We must decide: flip this '0' to '1', or flip previous 1's to 0
                if (countOne == 0) {
                    // No 1's before, so '0' is fine
                    continue;
                } else {
                    // Flip this 0 → 1
                    minFlips++;
                }
            } else {
                // it's a '1' → increase count of 1s
                countOne++;
            }

            // Optimization: it's cheaper to flip all previous 1's to 0
            minFlips = min(minFlips, countOne);
        }

        return minFlips;
    }
};
