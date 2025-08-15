class Solution {
    public int findClosestNumber(int[] nums) {
        int closest = nums[0]; // start with the first element

        for (int num : nums) {
            // If closer to zero OR equally close but positive

            if (Math.abs(num) < Math.abs(closest) || 
            
               (Math.abs(num) == Math.abs(closest) && num > closest)) {
            
                closest = num;
            }
        }

        return closest;
    }
}
