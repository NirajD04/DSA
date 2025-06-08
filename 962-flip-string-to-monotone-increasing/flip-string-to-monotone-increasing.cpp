class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int countOne = 0; // number of 1's seen so far (left side)

        int minFlips = 0; // flips needed

        for (char ch : s) {

            if (ch == '0') {

                minFlips++;
            } else {
                // it's a '1' → increase count of 1s
                countOne++;
            }
            minFlips = min(minFlips, countOne);
        }

        // Optimization: it's cheaper to flip all previous 1's to 0
    

    return minFlips;
}
};
