class Solution {
public:
    typedef pair<int, int> P;

    vector<vector<int>> direction{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<P> q;

        int freshorange = 0;
        int minute = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j}); // rotten oranges

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

               

                int i = q.front().first;   //row
                int j = q.front().second;  //coloum

                q.pop();

                for (auto& dir : direction) {

                    int new_x = i + dir[0];   //mov in direction ;
                    int new_y = j + dir[1];

                    if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n &&
                        grid[new_x][new_y] == 1) {


                        grid[new_x][new_y] = 2;
                        
                        q.push({new_x, new_y});

                        freshorange--;
                    }
                }
            }
            minute++;
        }
        return freshorange == 0 ? (minute - 1) : -1;
    }
};