class Solution {
public:
    int findPivot(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                low = mid + 1; // Pivot is on the right
            } else {
                high = mid; // Pivot is on the left
            }
        }

        return low; // Pivot index
    }

    int binarySearch(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1; // Target not found
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        if (n == 0)
            return -1;

        int pivot = findPivot(nums);

        if (nums[pivot] == target)
            return pivot;

        int idx = binarySearch(nums, 0, pivot-1, target);

        if(idx!=-1){
            return idx;
        }

        idx=binarySearch(nums, pivot, n-1,target);

        return idx;
    }
};
