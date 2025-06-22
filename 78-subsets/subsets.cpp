class Solution {
public:
    vector<vector<int>> ans;
    //     void solve(int idx,vector<int>& nums,  vector<int> temp) {
    //         if (idx == nums.size()) {
    //             ans.push_back(temp);
    //             return;
    //         }

    //         temp.push_back(nums[idx]);
    //         solve(idx + 1, nums, temp);
    //         temp.pop_back();
    //         solve(idx + 1, nums, temp);
    //     }
    //     vector<vector<int>> subsets(vector<int>& nums) {
    //         vector<int> temp;
    //         solve(0,nums, temp);
    //         return ans;
    //     }
    // };

    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();

        for (int num = 0; num < 1 << n; num++) {
        
            vector<int> temp;
            
            for (int i = 0; i < n; i++) {
                if (num & (1 << i)) {
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};