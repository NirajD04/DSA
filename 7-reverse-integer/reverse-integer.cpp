class Solution {
public:
    int reverse(int x) {
        int temp = 0;
        while (x != 0) {
        if (temp>INT_MAX/10 || temp<INT_MIN/10) return 0;
        int r = x % 10;
        temp = temp * 10 + r;
        x = x / 10;
        }
        return temp;
    }
};
