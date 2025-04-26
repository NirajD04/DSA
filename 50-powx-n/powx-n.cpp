class Solution {
public:
    double solve(double x, long long n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return solve(1 / x, -n);
        }
        if (n % 2 == 0) {
            return solve(x * x, n / 2);
        } else
            return x * solve(x * x, n / 2);
    }
    double myPow(double x, int n) {
        // double result=1;

        //   if (n < 0) {
        //     x = 1 / x;
        //     n = -n;
        // }

        // for (int i = 0; i < n; i++) {
        //     result *= x;
        // }

        // return result;

        return solve(x, n);
    }
};