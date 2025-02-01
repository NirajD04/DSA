class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        set<int> ans;
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;

            // Check if the current element is the majority
            if (mp[nums[i]] > n / 3) {
                  ans.insert(nums[i]);
            }
        }
        vector<int>ans2;
        for(auto s:ans){
            ans2.push_back(s);
        }
        return ans2;

    }
};