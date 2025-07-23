class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int missing=1;
        for(int i=0; i< nums.size(); i++){
            if(nums[i] == missing){
            missing++;
            continue;
       
            }
            if(nums[i]> missing){
                return missing;
            }
        }

        return missing;
    }
};
