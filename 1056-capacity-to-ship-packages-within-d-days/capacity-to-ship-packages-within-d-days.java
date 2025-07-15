import java.util.*;

class Solution {

    // Helper method to check if capacity is enough
    public boolean canShip(int[] weights, int days, int capacity) {
        int currentLoad = 0;
        int requiredDays = 1;

        for (int weight : weights) {
            if (currentLoad + weight > capacity) {
                requiredDays++;
                currentLoad = 0;
            }
            currentLoad += weight;
        }

        return requiredDays <= days;
    }

    public int shipWithinDays(int[] weights, int days) {
        int low = Arrays.stream(weights).max().getAsInt();     // min possible capacity
        int high = Arrays.stream(weights).sum();               // max possible capacity

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canShip(weights, days, mid)) {
                high = mid - 1; // Try a smaller capacity
            } else {
                low = mid + 1;  // Need more capacity
            }
        }

        return low;  // The minimum capacity that works
    }
}
