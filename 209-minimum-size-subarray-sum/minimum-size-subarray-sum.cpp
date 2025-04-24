class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0;
        int minlength = INT_MAX;  // Use INT_MAX for correct min comparison

        while (r < n) {
            sum += nums[r];

            // Shrink the window as long as the sum is valid
            while (sum >= target) {
                minlength = min(minlength, r - l + 1);
                sum -= nums[l];
                l++;
            }

            r++;
        }

        return (minlength == INT_MAX) ? 0 : minlength;
    }
};
