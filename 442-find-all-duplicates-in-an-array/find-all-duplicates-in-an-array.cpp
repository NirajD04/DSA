class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // int n = nums.size();
        // unordered_map<int, int> freq;
        // for (auto x : nums) {
        //     freq[x]++;
        // }

        // vector<int> ans;
        // for (auto x : freq) {
        //     if (x.second > 1) {
        //         ans.push_back(x.first);
        //     }
        // }

        // return ans;

        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;

            if (nums[idx] < 0) {
                res.push_back(abs(nums[i])); // duplicate found
            } else {
                nums[idx] = -nums[idx]; // mark as visited
            }
        }

        return res;
    }
};