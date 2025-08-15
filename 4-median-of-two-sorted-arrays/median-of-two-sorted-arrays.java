import java.util.*;

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int a = nums1.length;
        int b = nums2.length;
        
        // Create a combined array
        int[] merged = new int[a + b];
        
        // Copy nums1
        for (int i = 0; i < a; i++) {
            merged[i] = nums1[i];
        }
        
        // Copy nums2
        for (int i = 0; i < b; i++) {
            merged[a + i] = nums2[i];
        }
        
        // Sort the merged array
        Arrays.sort(merged);
        
        int n = a + b;
        
        // Find median
        if (n % 2 == 0) {
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        } else {
            return merged[n / 2];
        }
    }
}
