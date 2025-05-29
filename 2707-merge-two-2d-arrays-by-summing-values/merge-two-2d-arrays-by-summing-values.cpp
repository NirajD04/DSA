class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> mp;

        // Add all values from nums1
        for (auto& v : nums1) {
            mp[v[0]] += v[1];
        }

        // Add all values from nums2
        for (auto& v : nums2) {
            mp[v[0]] += v[1];
        }

        // Convert map to vector
        vector<vector<int>> ans;
        for (auto& [id, val] : mp) {
            ans.push_back({id, val});
        }

        return ans;
    }
};
