class Solution {
public:
    int findsum(int i) {
        int sum = 0;
        while (i > 0) {
            sum += i % 10;
            i = i / 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int maxsize = 0;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            int digitsum = findsum(i);
            mp[digitsum]++;

            if (mp[digitsum] == maxsize) {
                count++;
            } else if (mp[digitsum] > maxsize) {
                maxsize = mp[digitsum];
                count = 1;
            }
        }
        return count;
    }
};