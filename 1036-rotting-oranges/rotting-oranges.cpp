class Solution {
public:
    typedef pair<int, int> P;

    vector<vector<int>> direction{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<P> q;

        int freshorange = 0;
        int minutes = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshorange++;
                }
            }
        }

        if (freshorange == 0)
            return 0;

        while (!q.empty()) {
            int N = q.size();

            while (N--) {
                auto curr = q.front();
                int i = curr.first;
                int j = curr.second;
                q.pop();
                for (auto& dir : direction) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n &&
                        grid[new_i][new_j] == 1) {
                        grid[new_i][new_j] = 2; // mark as rotten
                        q.push({new_i, new_j});
                        freshorange--;
                    }
                }
               
            }
             minutes++;
        }
        return freshorange == 0 ? (minutes - 1) : -1;
    }
};