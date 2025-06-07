class Solution {
public:
    // Helper to check if a given divisor keeps sum within threshold
    bool canDivide(vector<int>& nums, int threshold, int divisor) {
        int total = 0;
        for (int x : nums) {
            total += x / divisor;
            if (x % divisor != 0) total++;
        }
        return total <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (canDivide(nums, threshold, mid)) {
                r = mid;  // try smaller divisor
            } else {
                l = mid + 1; // divisor too small
            }
        }
        return l;
    }
};
