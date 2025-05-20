class Solution {
public:
    set<vector<int>> ans;

    void solve(int idx, vector<int>& nums, vector<int> temp) {
        if (idx >= nums.size()) {
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solve(idx + 1, nums, temp);
        temp.pop_back();
        solve(idx + 1, nums, temp);
    }



    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;

        sort(nums.begin(), nums.end());

        solve(0, nums, temp);
        vector<vector<int>> result(ans.begin(), ans.end());
        return result;
    }
};