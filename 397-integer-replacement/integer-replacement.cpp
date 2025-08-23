class Solution {
public:
    int integerReplacement(long long n) {  // long long to handle overflow
        if (n == 1) return 0;

        if (n % 2 == 0) {
            return 1 + integerReplacement(n / 2); // one step
        } else {
            return 1 + min(integerReplacement(n - 1), integerReplacement(n + 1));
        }
    }
};
