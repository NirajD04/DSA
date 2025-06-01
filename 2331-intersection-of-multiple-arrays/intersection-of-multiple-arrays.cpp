class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();

        for (auto &row : nums) {
            unordered_set<int> unique(row.begin(), row.end()); // avoid duplicates in a row
            for (int num : unique) {
                freq[num]++;
            }
        }

        vector<int> ans;
        for (auto &[num, count] : freq) {
            if (count == n) {  // appears in all arrays
                ans.push_back(num);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
