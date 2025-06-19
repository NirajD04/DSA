class Solution {
    public int diagonalSum(int[][] mat) {
        int m=mat.length;
        int n=mat[0].length;
        int sum=0;

        for(int i=0;i<m; i++){
           sum+=mat[i][i];
           sum+=mat[i][n-1-i];
        }
        if(n%2!=0){
        sum-= mat[n/2][n/2];
        }
        return sum;
    }
}