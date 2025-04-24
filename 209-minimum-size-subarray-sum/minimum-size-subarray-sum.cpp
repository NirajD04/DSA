class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=0;
        int sum=0;
        int minl=INT_MAX;


        while(r< nums.size()){
            sum += nums[r];

            while(sum>= target){
                minl=min(minl, r-l+1);
                sum=sum-nums[l];
                l++;
            }
            r++;
        }
        return minl==INT_MAX ? 0 : minl ;
    }
};