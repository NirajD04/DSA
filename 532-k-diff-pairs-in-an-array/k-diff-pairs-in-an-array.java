import java.util.*;

class Solution {
    public int findPairs(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        
        // Count frequency of each number
        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }
        
        int count = 0;
        
        for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
            int key = entry.getKey();
            int value = entry.getValue();
            
            if (k == 0) {
                if (value > 1) {
                    count++;
                }
            } else if (freq.containsKey(key + k)) {
                count++;
            }
        }
        
        return count;
    }
}
