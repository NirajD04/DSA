class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int a=0;
        for(int num:nums){
            a^=num;
        }
        return a;

    //      int left = 0, right = nums.size() - 1;

    //     while (left < right) {
    //         int mid = left + (right - left) / 2;
            
    //         // Ensure mid is even (pair index)
    //         if (mid % 2 == 1) mid--;

    //         // If pair is valid, move right
    //         if (nums[mid] == nums[mid + 1]) {
    //             left = mid + 2;
    //         } else {
    //             right = mid;
    //         }
    //     }

    //     return nums[left];
    // }
    }

};