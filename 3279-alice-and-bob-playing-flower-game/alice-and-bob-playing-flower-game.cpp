class Solution {
public:
    // long long flowerGame(int n, int m) {
    //     long long count = 0;
    //     for (int x = 1; x <= n; x++) {
    //         for (int y = 1; y <= m; y++) {
    //             if ((x + y) % 2 == 1) {
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;

    long long flowerGame(int n, int m) {
        long long odd_n = (n + 1) / 2;
        long long even_n = n / 2;
        long long odd_m = (m + 1) / 2;
        long long even_m = m / 2;
        return odd_n * even_m + even_n * odd_m;
    }
};
