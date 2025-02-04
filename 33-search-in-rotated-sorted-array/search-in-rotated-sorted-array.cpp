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

            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        return -1; // Target not found
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        int pivot = findPivot(nums);

        if (nums[pivot] == target) return pivot;

        if (pivot == 0 || target < nums[0]) { 
            // Search in the right half
            return binarySearch(nums, pivot, n - 1, target);
        } else { 
            // Search in the left half
            return binarySearch(nums, 0, pivot - 1, target);
        }
    }
};

//     int search(vector<int>& nums, int target) {
//         // int n=nums.size();
//         // int low=0;
//         // int high=n-1;
//         // int mid= low+(high-low) / 2;

        
//         // while(low<=high){
//         //     int mid= low+(high-low) / 2;


//         //     if(nums[mid]==target){
//         //         return mid;
//         //     }



//         //     if(nums[low]<=nums[mid]){
//         //         if(nums[low]<= target && target<= nums[mid]){
//         //             high=mid-1;
//         //         }
//         //         else{
//         //             low = mid+1;
//         //         }

//         //     }


//         //     else{
//         //         if(nums[mid]< target && target <= nums[high]){
//         //             low =mid+1;
//         //         }
//         //         else{
//         //             high =mid-1;
//         //         }
//         //     }


//         // }
//         // return -1;
//     }
// };