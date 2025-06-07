class Solution {
public:
    int findMin(vector<int>& nums) {
        //    int left = 0, right = nums.size() - 1;

        //     while (left < right) {
        //         int mid = left + (right - left) / 2;

        //         if (nums[mid] > nums[right]) {
        //             // Minimum is in the right half
        //             left = mid + 1;
        //         } else {
        //             // Minimum is in the left half (including mid)
        //             right = mid;
        //         }
        //     }

        //     return nums[left];

        // int n = .size();

        int min = nums[0];
        int min_index = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < min) {
                min = nums[i];
                min_index = i;
            }
        }
        return min;
    }
};