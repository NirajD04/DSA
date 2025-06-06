class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=INT_MIN;
        int currsum=0;

        for(int i=0; i<nums.size(); i++){

            currsum+=nums[i];

            if(maxsum<currsum){
                maxsum=currsum;
            }

            if(currsum<0){
                currsum=0;
            }
            // maxsum=max(maxsum, currsum);
        }
        return maxsum;
    }
};