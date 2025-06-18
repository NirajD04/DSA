import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;  // ✅ Use .length for arrays
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int more = target - nums[i];
            if (map.containsKey(more)) {  // ✅ method is containsKey (not containKey)
                return new int[]{i, map.get(more)};  // ✅ Correct return syntax
            }
            map.put(nums[i], i);  // ✅ Key = nums[i], Value = i
        }
        return new int[]{-1, -1};  // ✅ Return default array
    }
}
