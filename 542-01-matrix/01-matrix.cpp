class Solution {
public:
    vector<vector<int >> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();


        vector<vector<int>> dist(m , vector<int>(n, INT_MAX));  // infinty se intialise kardiya

        queue<pair<int, int>> q;

        // Initialize the queue with all 0s and set their distance to 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    
                    q.push({i, j});     // multiple bfs 
                }
            }
        }

      
        while (!q.empty()) {

            int x = q.front().first;
            int y=q.front().second;

            q.pop();

            for (auto dir: directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                // If neighbor is within bounds and has a greater distance, update it

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx][ny] > dist[x][y] + 1) {

                    dist[nx][ny] = dist[x][y] + 1;

                    q.push({nx, ny});

                }
            }
        }

        return dist;
    }
};
