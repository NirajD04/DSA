class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lsum=0;
        int rsum=0;
        int maxsum=0;

        for(int i=0;i<k; i++){
            lsum+= cardPoints[i];
        }
        maxsum=lsum;

        for(int i=0; i<k;i++){
            lsum-= cardPoints[k-1-i];
            rsum+=cardPoints[n-1-i];
            maxsum=max(maxsum, lsum+rsum);
        }
        return maxsum;
    }
};