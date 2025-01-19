class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        return (n & (n - 1)) == 0;

        // int count = 0;
        // while (n) {
        //     if (n & 1) {
        //         count++;
        //     }
        //     n = n >> 1;
        // }
        // if (count == 1) {
        //     return true;
        // }
        // return false;
    }
};