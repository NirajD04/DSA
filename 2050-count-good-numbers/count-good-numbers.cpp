class Solution {
public:
    const int MOD = 1e9 + 7;

    long long solve(long long x, long long n) {
        if (n == 0) {
            return 1;
        }
        if (n % 2 == 0) {
            long long half = solve((x * x) % MOD, n / 2);
            return half % MOD;
        } else {
            long long half = solve((x * x) % MOD, n / 2);
            return (x % MOD * half % MOD) % MOD;
        }
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;

        long long evenPart = solve(5, evenCount);
        long long oddPart = solve(4, oddCount);

        return (evenPart * oddPart) % MOD;
    }
};
