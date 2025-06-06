class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();        // Rows
        int m = matrix[0].size();     // Columns

        vector<vector<int>> result(m, vector<int>(n));  // m rows, n cols

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[j][i] = matrix[i][j];
            }
        }

        return result;
    }
};
