class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(); //rows
        int n = grid[0].size(); //cols
        vector<vector<int>> temp(m, vector<int>(n, 0));

        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                int newVal = ((r*n + c) + k) % (m*n);//index of 2-d to 1d rowno*nofcol+colno
                //+k is for shifting and mod is handling next row,col index to jump
                int newr = newVal/n;//1d to 2-d row=r/nofcol
                int newc = newVal%n;//1d to 2d col=c%nofcol
                temp[newr][newc] = grid[r][c];
                
            }
        }
        return temp;
    }
};