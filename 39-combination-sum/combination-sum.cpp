class Solution {
public:
    void solve(int ind, int target, vector<int>& candidates, vector<int> temp,
               vector<vector<int>>& ans) {
        if (ind == candidates.size()) {
            if (target == 0) {
                ans.push_back(temp);
            }
            return;
        }

        if (candidates[ind] <= target) {
            temp.push_back(candidates[ind]);
            solve(ind, target - candidates[ind], candidates, temp, ans);
            temp.pop_back();
        }

        solve(ind + 1, target, candidates, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;

        solve(0, target, candidates, temp, ans);
        return ans;
    }
};