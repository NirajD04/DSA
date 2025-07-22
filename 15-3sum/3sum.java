import java.util.*;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);  // Required for two-pointer and duplicate skipping

        int n = nums.length;

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;  // Skip duplicates for the first element

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    ans.add(Arrays.asList(nums[i], nums[l], nums[r]));

                    // Skip duplicates
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;

                    // Move both pointers after a valid triplet
                    l++;
                    r--;
                } else if (sum < 0) {
                    l++;  // Need a bigger sum
                } else {
                    r--;  // Need a smaller sum
                }
            }
        }

        return ans;
    }
}
