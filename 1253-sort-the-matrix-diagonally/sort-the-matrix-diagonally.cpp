class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, vector<int>> mp;

        // Store all diagonals in map
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i - j].push_back(mat[i][j]);
            }
        }

        // Sort each diagonal in descending order so we can pop from the back (faster)
        for (auto& [key, vec] : mp) {
            sort(vec.begin(), vec.end(), greater<int>());
        }

        // Put back sorted values into mat
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }

        return mat;
    }
};
