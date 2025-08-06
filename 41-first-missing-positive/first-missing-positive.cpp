// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         int missing = 1;

//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == missing) {
//                 missing++;
//                 continue;
//             }
//             if (nums[i] > missing) {
//                 return missing;
//             }
//         }

//         return missing;
//     }
// };


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            // Place nums[i] at correct index if it's in range [1, n]
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Find the first place where index+1 != value
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1)
                return i + 1;
        }

        // All values from 1 to n are present
        return n + 1;
    }
};
