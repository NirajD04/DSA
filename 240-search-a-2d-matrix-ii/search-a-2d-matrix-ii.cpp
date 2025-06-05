class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
          int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n - 1;   // start with top right corner

        while (i < m && j >= 0) { 

            if (matrix[i][j] == target)
                return true;
            
            else if (matrix[i][j] > target)   // left ja 
                j--; // move left
            
            else
                i++; // move down               // niche ke row me dekh 7->20 pe ayege 
        }
        return false;
    }
};