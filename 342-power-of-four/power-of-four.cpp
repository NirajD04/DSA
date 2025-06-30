class Solution {
public:
    bool isPowerOfFour(int n) {
        // Check if only one bit is set (power of 2) AND
        // that bit is in even position
        return n > 0 && (n & (n - 1)) == 0 && (n % 3 == 1);
    }
};
