class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;

            // Check if the current element is the majority
            if (mp[nums[i]] > n / 2) {
                return nums[i];
            }
        }
        return -1;

        // sort(nums.begin(), nums.end());

        // return nums[m/2];
    }
};