class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) return 0;

        Arrays.sort(nums);
        int maxCount = 1;
        int count = 1;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1]) {
                // skip duplicates
                continue;
            } else if (nums[i] == nums[i - 1] + 1) {
                count++; // consecutive
            } else {
                count = 1; // reset for new sequence
            }
            maxCount = Math.max(maxCount, count);
        }

        return maxCount;
    }
}