class Solution {
public:
    int getnext(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        set<int> visited;
        while (visited.find(n) == visited.end()) {
            visited.insert(n);
            n = getnext(n);
            if (n == 1) {
                return true;
            }
        }
        return false;
    }
};