class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        int sum = 0;

        // Sort each row in descending order
        for (int i = 0; i < m; i++) {
            sort(nums[i].begin(), nums[i].end(), greater<int>());
        }

        // For each column, find the max among all rows at that column
        for (int j = 0; j < n; j++) {
            int max_col_val = 0;
            for (int i = 0; i < m; i++) {
                max_col_val = max(max_col_val, nums[i][j]);
            }
            sum += max_col_val;
        }

        return sum;
    }
};
