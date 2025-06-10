class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>> mp;
        vector<int> ans;

        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        bool flip = true;
        for (auto x : mp) {
            if (flip) {
                reverse(x.second.begin(), x.second.end());
            }

            for (auto it : x.second) {
                ans.push_back(it);
            }
            flip = !flip;
        }
        return ans;
    }
};