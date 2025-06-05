class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int closestSum = nums[0] + nums[1] + nums[2]; // Initialize with first triplet

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (abs(target - sum) < abs(target - closestSum)) {
                    closestSum = sum;
                }

                if (sum < target) {
                    l++;  // Need a larger sum
                } else {
                    r--;  // Need a smaller sum
                }
            }
        }

        return closestSum;
    }
};
