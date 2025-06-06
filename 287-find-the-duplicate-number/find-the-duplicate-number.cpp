class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int slow = nums[0];
        // int fast = nums[0];

        // slow = nums[slow];
        // fast = nums[nums[fast]];

        // while (slow != fast) {
        //     slow = nums[slow];
        //     fast = nums[nums[fast]];
        // }

        // slow = nums[0];
        // while (slow != fast) {
        //     slow = nums[slow];
        //     fast = nums[fast];
        // }

        // return slow;

        unordered_map<int, int> freq;

        for (auto x : nums) {
            freq[x]++;
        }

        for (auto x : freq) {
            if (x.second > 1) {
                return x.first;
            }
        }
        return -1;
    }
};