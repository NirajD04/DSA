class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        
        int actualsum = 0;
        for (int i = 0; i < n; i++) {
            actualsum += nums[i];
        }
        return sum - actualsum;

        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // int i = 0;
        // for(int j = 0;j<n;j++){
        //     if(nums[j]!=i){
        //         return i;
        //     }
        //     i++;
        // }
        // return n;
     
    }
};