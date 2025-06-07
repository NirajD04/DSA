class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int n=mat.size();
        for(int i=0; i<n; i++){
            sum+= mat[i][i]; // 00 11  22

            sum+= mat[i][n-1-i]; // 30 ,22 , 
        }

        if(n%2!= 0){
            sum -= mat[n/2][n/2];
        }
        return sum;
    }
};