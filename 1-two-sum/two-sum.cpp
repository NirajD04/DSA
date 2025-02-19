class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        int more = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            more = target - nums[i];

            if (mp.find(more) != mp.end()) {
                return { mp[more], i};
                
            }
            
            mp[nums[i]] = i;
            
        }
        return {-1, -1};
    }
};